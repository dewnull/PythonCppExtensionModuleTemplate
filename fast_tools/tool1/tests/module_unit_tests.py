
import unittest
from fast_tools.tool1 import run_single_cal


class VlidationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            ### LOAD SPECIFIC DATA SET

        except NativeModule.error as e:
            cls.tearDownClass()
            raise Exception("Faild with" +str(e))

    def test_division(self):
        data= {'operand1':10,
               'operand2':2,
               'operation': '/'}
        response = run_single_cal(data)
        expected = {'result1':5,
                    'result2':20}

        for ky in expected:
            self.assertTrue(expected[ky] == response[ky], 'expected['+str(ky)+'] = '+str(expected[ky])+' but got '+str(response[ky]))
    def test_addition(self):
        data= {}
        response = run_single_cal(data)
        expected = {}

        for ky in expected:
            self.assertTrue(expected[ky] == response[ky], 'expected['+str(ky)+'] = '+str(expected[ky])+' but got '+str(response[ky]))


if __name__ == '__main__':
    import xmlrunner
    unittest.main(
            testRunner=xmlrunner.XMLTestRunner(output='test-reports')
            )
