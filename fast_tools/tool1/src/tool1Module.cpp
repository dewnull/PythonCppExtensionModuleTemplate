
#include <Python.h>
#include <string>
#include <map>
#include "MathFuncsLib.h"


static PyObject *fastModuleError;


PyObject* buildPythonDictionary()
{
	// this function uses the C API for Python to create and return a
	// Python dictionary with all the outputs relevent to the user

    PyObject *d = PyDict_New();
	//FORMAT:   key , type(s for string, i for integer, d for double, ...) , actual value
    PyDict_SetItemString(d, "symbolic", Py_BuildValue("s", "string result"));
    PyDict_SetItemString(d, "result", Py_BuildValue("d", 2.01));

    PyObject *pList = PyList_New(3); // new reference
    assert(PyList_Check(pList));

    // set some initial values
    for (int i = 0; i < 3; ++i)
        PyList_SetItem(pList,i, Py_BuildValue("s", std::string("a warning #"+i).c_str()));

    PyDict_SetItemString(d, "WARNING", pList);

    // clean up
    Py_DECREF(pList);
    return d;
}

static PyObject *getSizeOfTwoStrings(PyObject *self, PyObject *args)
{
    const char *inputString1;
    const char *inputString2;


    if (!PyArg_ParseTuple(args, "ss", &inputString1, &inputString1)){
        PyErr_SetString(fastModuleError, "Bad input. please provide two strings");
        return NULL;
    }
    int sts = std::sting(inputString1).size() + std::sting(inputString2);
    return PyLong_FromLong(sts);
}


PyObject *demoOfPythonDict(PyObject *, PyObject *args){

  PyObject* pyDic = Py_None;


  if (!PyArg_ParseTuple(args, "O!", &PyDict_Type, &pyDic) || !PyDict_Check(pyDic))
  {
      PyErr_SetString(Cessna560XLSModuleError, "Input Data is not Python Dictionary");
      return NULL;
  }

  PyObject* anItem = PyDict_GetItemString(pyDic, "operation");
      if (!anItem){
          PyErr_SetString(fastModuleError, "operation not found");
          return NULL;
      }
      PyObject* bytes = PyUnicode_AsEncodedString(anItem, "utf-8", "surrogateescape");
      if (!bytes) {
          PyErr_SetString(fastModuleError, "operation not utf-8");
          return NULL;
      }
      const char* operation = PyBytes_AsString(bytes);

      anItem = PyDict_GetItemString(pyDic, "operand1");
      if (!anItem){
          PyErr_SetString(fastModuleError, "operand1 not found");
          return NULL;
      }
      double op1 = PyFloat_AsDouble(anItem);

      anItem = PyDict_GetItemString(pyDic, "operand2");
      if (!anItem){
          PyErr_SetString(fastModuleError, "operand2 not found");
          return NULL;
      }
      double op2 = PyFloat_AsDouble(anItem);

    double results=0;
    try
    {
        results = MathFuncs::MyMathFuncs::Add(op1, op2);
    }
    catch (std::runtime_error &e)
    {
        errorMessage = "Caught a runtime_error exception :" +
            std::string(e.what());
        PyErr_SetString(fastModuleError, errorMessage.c_str());
        return NULL;
    }
    catch (std::exception &e)
    {
        errorMessage = "Caught an exception of an unexpected type: " +
            std::string(e.what());
        PyErr_SetString(fastModuleError, errorMessage.c_str());
        return NULL;
    }
    catch (...)
    {
        errorMessage = "Caught an unknown exception\n";
        PyErr_SetString(fastModuleError, errorMessage.c_str());
        return NULL;
    }

    return buildPythonDictionary();
}



static PyObject *keywordArgDemo(PyObject *self, PyObject *args, PyObject *keywds)
{

	const char *_operand1; //!< operand one
	double _operand2 = NULL;   //!< operand two
	const char *_operator;   //!< the operator sign

	int numberOfLoadedTables = -1;   //!< The number of loaded tables, -1 indicates and error
	static char *kwlist[] = { "operand1","operator","operand2", NULL };

	if (!PyArg_ParseTupleAndKeywords(args, keywds, "ds|d", kwlist,
		&_operand1, &_operator, &_operand2,))
	{
		PyErr_SetString(fastModuleError, "Bad input.");
		return NULL;
	}


	std::string operatorSign = std::string(_operator);



	return PyLong_FromLong();
}

static PyMethodDef fast_module_methods[] = {
    // PythonName,  c++ functionName,  argument presentation,  description
    { "getSizeOfTwoStrings", getSizeOfTwoStrings, METH_VARARGS, "returns the size of two utf-8 strings" },
    { "demoOfPythonDict", demoOfPythonDict, METH_VARARGS, "input is a python dictionary out put is a python dictionary" },
	{ "keywordArgDemo", (PyCFunction)keywordArgDemo, METH_VARARGS | METH_KEYWORDS, "input is keyword argument  'operand1', 'operation', 'operand2'" },
    { NULL, NULL, 0, NULL }        /* Sentinel */
};

static PyModuleDef fast_module_module = {
    PyModuleDef_HEAD_INIT,
    "fast_module",   /* name of module */
    "simple calculator in c++", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    fast_module_methods
};
PyMODINIT_FUNC PyInit_fast_module(void){
    PyObject *m;

    m = PyModule_Create(&fast_module_module);
    if (m == NULL)
        return NULL;

    fastModuleError = PyErr_NewException("fast_module.error", NULL, NULL);
    Py_INCREF(fastModuleError);
    PyModule_AddObject(m, "error", fastModuleError);
    return m;
}
