* drogon是以submodule添加的，clone时注意加上：`--recursive`
* drogon还包含子模块trantor，注意使用：
  ```bash
  cd vendor/drogon
  git submodule update --init
  ```


* mac下build前需要安装如下库
```bash
brew install coreutils cmake jsoncpp ossp-uuid openssl doxygen googletest
```