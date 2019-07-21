"""
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

string could be empty and contains only lowercase letters a-z.
pattern could be empty and contains only lowercase letters a-z, and characters like . or *.

"""


class BaseSymbol:
    def __init__(self, pattern):
        self.patterns = self.get_patterns(pattern)

    def get_patterns(self, pattern) -> list:
        raise NotImplemented

    def clean_string(self, string) -> str:
        raise NotImplemented

    @classmethod
    def from_string(cls, pattern, string) -> str:
        raise NotImplemented


class AnySingleCharacter(BaseSymbol):

    def __init__(self, pattern):
        super().__init__(pattern)

    def get_patterns(self, pattern) -> list:
        return [pattern.index(index_pattern) for index_pattern in pattern.split('.')][:-1]

    def clean_string(self, string) -> str:
        for pattern_index in self.patterns:
            string = self.remove_index_from_string(pattern_index, string)
        return string

    @staticmethod
    def remove_index_from_string(pattern_index, string) -> str:
        return string[0:pattern_index] + string[pattern_index + 1: len(string)]

    @classmethod
    def from_string(cls, pattern, string) -> str:
        if pattern.__contains__('.'):
            return cls(pattern).clean_string(string)
        else:
            return string


class PrecedingElement(BaseSymbol):

    def __init__(self, pattern):
        super().__init__(pattern)

    def get_patterns(self, pattern) -> list:
        return pattern.split('*')

    def clean_string(self, string) -> str:
        for index, part_pattern in enumerate(self.patterns):
            part_pattern_clean = part_pattern
            if part_pattern == '.':
                part_pattern_clean = string[index-1 if index is not 0 else 0:]
            string = self.clean_part_string(part_pattern_clean, string)
        return string

    @staticmethod
    def clean_part_string(part_pattern_clean, string) -> str:
        return string.replace(part_pattern_clean, '')

    @classmethod
    def from_string(cls, pattern, string) -> str:
        if pattern.__contains__('*'):
            return cls(pattern).clean_string(string)
        else:
            return string


CLEAN_SYMBOLS = [PrecedingElement, AnySingleCharacter]


def match(string: str, pattern: str) -> bool:
    if string == '':
        return False
    if is_equal_comparison(pattern):
        return string == pattern
    else:
        for clean_symbol in CLEAN_SYMBOLS:
            string = clean_symbol.from_string(pattern, string)
            if string == '':
                break
        return string == ''


def is_equal_comparison(pattern) -> bool:
    return '*' not in pattern and '.' not in pattern
