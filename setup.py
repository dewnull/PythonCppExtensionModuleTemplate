from setuptools import setup, Extension, find_packages
import os
import subprocess

def getVersion():
    """Fetch version from git tags, and write to version.py.
    Also, when git is not available, use stored version.py.
    """
    version_py = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'fast_tools/tool1/version.py')
    try:
        version_git = subprocess.check_output(["git", "describe", "--tags"]).rstrip()
    except:
        with open(version_py, 'r') as fh:
            version_git = open(version_py).read().strip().split('=')[-1].replace("'",'')
    version_msg = "# CHANGES IN THIS FILE WILL BE OVERWRITTEN. VERSIONING IS GOVERNED BY GIT"

    with open(version_py, 'w') as fh:
        version_git = version_git.decode('utf-8')
        if version_git[0] == 'v' or version_git[0] == 'V':
            version_git = version_git[1:]
        fh.write(version_msg +'\n'+"__version__ =" + "'"+version_git+"'\n")
        fh.close()
    return '{ver}'.format(ver=version_git)


module1 = Extension('fast_tools.tool1',
                    sources =['fast_tools/tool1/src/tool1Module.cpp'],

                    depends =['fast_tools/tool1/include/helper.h'],

               include_dirs =['fast_tools/tool1/libs/',
                              'fast_tools/tool1/include/'],

                    extra_compile_args =['-std=c++11'],
            define_macros =[('Py_LIMITED_API',None)])

setup (namespace_packages= ['fast_tools'],
       name='fast_tools.tool1',
       packages=find_packages(exclude=['test']),
       #install_requires=[ ''],
       #package_dir= {'': ''},
       description='fast tool to calculate performance',
       version=getVersion(),
       include_package_data=True,
       package_data={'fast_tools.tool1':['data/*.db']},
       author='Author Lastname1, Author Lastname2',
       author_email='author1@domain.com, author2@domain.com',
       license='Copyright (c) 2016' ,
       url='https://github.com/',
       ext_modules=[module1])
