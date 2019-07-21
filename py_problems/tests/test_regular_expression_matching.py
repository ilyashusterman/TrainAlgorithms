from unittest import TestCase

from py_problems.regular_expression_matching import match


class TestRegularExpressionMatching(TestCase):
    """
    Example 1:
    Input:
    s = "aa"
    p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

    Example 2:
    Input:
    s = "aa"
    p = "a*"
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

    Example 3:
    Input:
    s = "ab"
    p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".

    Example 4:
    Input:
    s = "aab"
    p = "c*a*b"
    Output: true
    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

    Example 5:
    Input:
    s = "mississippi"
    p = "mis*is*p*."
    Output: false

    """
    def test_match_string_aa(self):
        self.assertFalse(match(string='aa', pattern='a'))

    def test_match_string_repeating(self):
        self.assertTrue(match(string='aa', pattern='a*'))
        self.assertTrue(match(string='aaa', pattern='a*'))
        self.assertTrue(match(string='aaaa', pattern='a*'))
        self.assertTrue(match(string='a', pattern='a*'))

    def test_match_any_character_string_repeating(self):
        self.assertTrue(match(string='ab', pattern='.*'))

    def test_match_any_character_string_repeating_times(self):
        self.assertTrue(match(string='aab', pattern='c*a*b'))

    def test_match_any_character_string_repeating_times_dot_last(self):
        self.assertFalse(match(string='mississippi', pattern='mis*is*p*.'))

    def test_match_any_character_string_dot(self):
        self.assertTrue(match(string='a', pattern='.'))

    def test_match_empty_pattern(self):
        self.assertFalse(match(string='aasdasd', pattern=''))

    def test_match_empty_string(self):
        self.assertFalse(match(string='', pattern='absd*.'))
