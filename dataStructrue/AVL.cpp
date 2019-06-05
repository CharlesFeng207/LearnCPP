#include <iostream>
#include <string>

using namespace std;

typedef char KeyType; //关键字

typedef struct MyRcdType //记录
{
    KeyType key;
    
} RcdType, *RcdArr;

typedef enum MyBFStatus //为了方便平衡因子的赋值，这里进行枚举
{ //RH,EH,LH分别表示右子树较高，左右子树等高，左子树较高

    RH,
    EH,
    LH

} BFStatus;

typedef struct MyBBSTNode //树结点类型定义
{
    RcdType data; //数据成员

    BFStatus bf; //平衡因子

    struct MyBBSTNode *lchild, *rchild; //左右分支

} BBSTNode, *BBSTree;