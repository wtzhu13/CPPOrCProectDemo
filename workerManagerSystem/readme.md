# 职工管理系统第一版

### 功能介绍
通过数字选择所要执行的功能：
    0.退出管理程序 
    1.增加职工信息
    2.显示职工信息  
    3.删除离职职工  
    4.修改职工信息  
    5.查找职工信息  
    6.按照编号排序  
    7.清空所有文档  

### 主要API
    void showMenu();
    void exitSys();
    void addWorker();
    void saveDataLocal(int id, string name, int departmentNum);
    void getWorkerCount(int *count);
    void initArray(int *countP);
    void deleteById();
    int IsExist(int id);
    void deleteWorker(int index);
    void test();
    void showWorker();
    void modifyWorkerInfo();
    void findWorker();
    void searcheByID();
    void searchByName();
    void waitQuit();
    void sortById();
    void clear();
    void clearFile();

