```shell
virtualenv -p python3 .venv
source .venv/bin/activate
pip install pybind11
```

Сборка кода:
```
g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)
```
