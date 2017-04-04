#!/usr/bin/env bash

APP_HOME="$(dirname "$(pwd)")"


# Delete previously built virtual env
if [ -d $APP_HOME/venv ]; then
    rm -rf $APP_HOME/venv/
fi
# Delete previously built distributions
if [ -d $APP_HOME/dist ]; then
    rm -rf $APP_HOME/dist/*
    rm -rf $APP_HOME/build/*
fi

# Create virtrual environment using pyvenv
pyvenv3 $APP_HOME/venv
source $APP_HOME/venv/bin/activate

# install the python modules
pip install --upgrade pip
pip install --upgrade setuptools
pip install unittest-xml-reporting
#pip install wheel

# build disrtubion to be installed
cd $APP_HOME

# install the python modules
python3 setup.py clean
python3 setup.py install

echo 'Running Validation Tests...'
python3 $APP_HOME/fast_tools/tool1/tests/module_unit_tests.py

echo 'done!'
