
#include <iostream>
#include <string>
#include <stdio.h>

#include <python3.6m/Python.h>


using namespace std;

PyObject * pModule = NULL;
PyObject * pFunc = NULL;
PyObject * pClass = NULL;
PyObject * pInstance = NULL;


/*

*/
void Mnist_recognition(int number,int time){
    /* build args */
   // PyObject *pArgs = PyTuple_New(1);

	PyObject *pArg = Py_BuildValue("(i,i)", number, time);  // 变量格式转换成python格式
 	//PyTuple_SetItem(pArgs,0, PyInt_FromLong(a));
	//这里是要调用的函数名
	pFunc= PyObject_GetAttrString(pModule, "tensorflow_predict");
	//调用函数
	PyEval_CallObject(pFunc, pArg );
}

int main(int argc,char *argv[]){


	Py_Initialize();
	if (!Py_IsInitialized())
	{
	return -1;
	}
	//导入当前路径
	PyRun_SimpleString("import  sys");
	PyRun_SimpleString("sys.path.append('./')");
	//PyRun_SimpleString("print(sys.path)");
	// PyImport_ImportModule函数载入python脚本，参数为为python脚本名称，因为是//模块化的导入，所以当代码处于运行期的时候就会生成一个.pyc文件，这样的话和直//接使用.pyc文件有同样的效果，下面做了两种方式运行效率的比较
	pModule = PyImport_ImportModule("MNIST_read_txt");//获取模块
	if (pModule == nullptr)
	{
	    PyErr_Print();
	    std::exit(1);
	}
	if (!pModule)
	{
	std::cout << pModule <<std::endl;
	return -1;
	}
	std::cout << "第一次预测" <<std::endl;

	// //bar_code_recognition(op,(int)(endTime - startTime)*1000 / CLOCKS_PER_SEC);

	// Py_Finalize();

    return 0;

}
