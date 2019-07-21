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
    def __init__(self, patterns):
        self.patterns = patterns

    def clean_string(self, string) -> bool:
        raise NotImplemented

    @classmethod
    def from_string(cls, pattern, string):
        raise NotImplemented


class AnySingleCharacter(BaseSymbol):

    def __init__(self, pattern):
        super().__init__(pattern)
        self.original_pattern = pattern
        self.patterns = [pattern.index(index_pattern) for index_pattern in pattern.split('.')][:-1]

    def clean_string(self, string) -> bool:
        for pattern_index in self.patterns:
            string = string[0:pattern_index] + string[pattern_index+1: len(string)]
        return string

    @classmethod
    def from_string(cls, pattern, string):
        if pattern.__contains__('.'):
            return cls(pattern).clean_string(string)
        else:
            return string


class PrecedingElement(BaseSymbol):

    def __init__(self, pattern):
        super().__init__(pattern)
        self.patterns = pattern.split('*')

    def clean_string(self, string) -> bool:

        did_not_match = string
        for index, word_pattern in enumerate(self.patterns):
            if word_pattern == '.':
                did_not_match = did_not_match.replace(did_not_match[index-1 if index is not 0 else 0:], '')
            else:
                did_not_match = did_not_match.replace(word_pattern, '')
        return did_not_match

    @classmethod
    def from_string(cls, pattern, string):
        if pattern.__contains__('*'):
            return cls(pattern).clean_string(string)
        else:
            return string


CLEAN_SYMBOLS = [PrecedingElement, AnySingleCharacter]


def match(string: str, pattern: str) -> bool:
    if is_equal_comparison(pattern):
        return string == pattern
    else:
        for clean_symbol in CLEAN_SYMBOLS:
            string = clean_symbol.from_string(pattern, string)
            if string == '':
                break
        return string == ''


def is_equal_comparison(pattern):
    return '*' not in pattern and '.' not in pattern
