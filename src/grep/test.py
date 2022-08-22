import os
import unittest

def calc(pattern, flag):
    os.system(f"grep {pattern} {flag} 1.txt 2.txt 3.txt > first")
    os.system(f"./s21_grep {pattern} {flag} 1.txt 2.txt 3.txt > second")
    os.system(f"diff first second > result")


def calc_f(flag):
    os.system(f"grep {flag} 4.txt 1.txt > first")
    os.system(f"./s21_grep {flag} 4.txt 1.txt > second")
    os.system(f"diff first second > result")


def calc_o(flag):
    os.system(f"grep {flag} 123 3.txt > first")
    os.system(f"./s21_grep {flag} 123 3.txt > second")
    os.system(f"diff first second > result")


class TestCat(unittest.TestCase):

    def test_no_flag(self):
        calc("aboba", "")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_i(self):
        calc("bebra", "-i")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_v(self):
        calc("s", "-v")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_c(self):
        calc("s", "-c")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_l(self):
        calc("s", "-l")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_n(self):
        calc("s", "-n")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_o(self):
        calc_o("-o")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_h(self):
        calc("aboba", "-h")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_s(self):
        calc("123123", "-s")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_f(self):
        calc_f("-f")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_in(self):
        calc("bebra", "-in")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_cv(self):
        calc("s", "-cv")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_iv(self):
        calc("s", "-iv")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_lv(self):
        calc("s", "-lv")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_ho(self):
        calc("aboba", "-ho")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_nf(self):
        calc_f("-nf")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")


if __name__ == '__main__':
    unittest.main()
