#include "gtest/gtest.h"
#include "structurerepresentor.h"
#include "myfactory.h"
#include<vector>
#include<QRandomGenerator>
#include<tuple>
#include "structurevisitor.h"
using std::vector;
typedef StructureRepresentor* Str;
const size_t Amount = 500;

void fillVectorDifferent(vector<int> &vec,const int& amount)
{
    for(size_t i = 0; i < amount; i++)
    {
        int a = QRandomGenerator::global()->bounded(-500,500);
        auto it = find_if(vec.begin(),vec.end(),[a](const int& elem){return a == elem;});
        if(it!=vec.end())
            i--;
        else{
            vec.push_back(a);
        }
    }
}

std::tuple<Str,Str,Str,Str> Initialization(const vector<int> &keys, const vector<int> &values){
    MyFactory* factory = MyFactory::getInstance();
    Str s1 = factory->createEssence("StlList");
    Str s2 = factory->createEssence("StlMap");
    Str s3 = factory->createEssence("SplayTree");
    Str s4 = factory->createEssence("RBTree");

    for(int i = 0; i < Amount;i++)
    {
        s1->insert(keys[i],values[i]);
        s2->insert(keys[i],values[i]);
        s3->insert(keys[i],values[i]);
        s4->insert(keys[i],values[i]);
    }
    return std::make_tuple(s1,s2,s3,s4);
}
void CleanUp(Str s1, Str s2, Str s3, Str s4){
    delete s1; delete s2; delete s3; delete s4;
}
TEST(AlgorithmsTest,Insert_Find_methods)
{
    vector<int>keys,values;
    fillVectorDifferent(keys,Amount);
    fillVectorDifferent(values,Amount);
    ASSERT_EQ(values.size(),Amount);
    ASSERT_EQ(values.size(),keys.size());

    auto [s1,s2,s3,s4] = Initialization(keys,values);

    for(size_t i = 0; i < Amount;i++)
    {
        EXPECT_EQ(s1->find(keys[i]),values[i]);
        EXPECT_EQ(s2->find(keys[i]),values[i]);
        EXPECT_EQ(s3->find(keys[i]),values[i]);
        EXPECT_EQ(s4->find(keys[i]),values[i]);
    }
    CleanUp(s1,s2,s3,s4);
}

TEST(AlgorithmsTest,Random_Insert_Find_RemoveMethods)
{
    vector<int>keys,values;
    fillVectorDifferent(keys,Amount);
    fillVectorDifferent(values,Amount);
    ASSERT_EQ(values.size(),Amount);
    ASSERT_EQ(keys.size(),values.size());

    auto [s1,s2,s3,s4] = Initialization(keys,values);

    for(size_t i = 0; i < Amount/2;i++)
    {
        s1->remove(keys[i]);
        s2->remove(keys[i]);
        s3->remove(keys[i]);
        s4->remove(keys[i]);
    }
    for(size_t i = 0; i < Amount/2;i++)
    {
        EXPECT_EQ(s1->find(keys[i]),int());
        EXPECT_EQ(s2->find(keys[i]),int());
        EXPECT_EQ(s3->find(keys[i]),int());
        EXPECT_EQ(s4->find(keys[i]),int());
    }
    for(size_t i = Amount/2; i < Amount;i++)
    {
        EXPECT_EQ(s1->find(keys[i]),values[i]);
        EXPECT_EQ(s2->find(keys[i]),values[i]);
        EXPECT_EQ(s3->find(keys[i]),values[i]);
        EXPECT_EQ(s4->find(keys[i]),values[i]);
    }
    CleanUp(s1,s2,s3,s4);
}

TEST(AlgorithmsTest,Clear_IsEmptyMethods)
{
    vector<int>keys,values;
    fillVectorDifferent(keys,Amount);
    fillVectorDifferent(values,Amount);
    ASSERT_EQ(values.size(),Amount);
    ASSERT_EQ(keys.size(),values.size());

    auto [s1,s2,s3,s4] = Initialization(keys,values);

    s1->clear();
    s2->clear();
    s3->clear();
    s4->clear();

    EXPECT_TRUE(s1->isEmpty());
    EXPECT_TRUE(s2->isEmpty());
    EXPECT_TRUE(s3->isEmpty());
    EXPECT_TRUE(s4->isEmpty());

    CleanUp(s1,s2,s3,s4);
}

TEST(PatternsTests,VisitorPattern)
{
    vector<int>keys,values;
    fillVectorDifferent(keys,Amount);
    fillVectorDifferent(values,Amount);
    ASSERT_EQ(values.size(),Amount);
    ASSERT_EQ(keys.size(),values.size());

    auto [s1,s2,s3,s4] = Initialization(keys,values);
    GetItemsVisitor<int,int> v1,v2,v3,v4;
    s1->accept(v1),s2->accept(v2),s3->accept(v3),s4->accept(v4);

    for(size_t i = 0; i < Amount; i++)
    {
        auto it11 = find(keys.begin(),keys.end(),v1.keys[i]);
        auto it12 = find(values.begin(),values.end(),v1.values[i]);
        EXPECT_NE(it11,keys.end()); EXPECT_NE(it12,values.end());

        auto it21 = find(keys.begin(),keys.end(),v2.keys[i]);
        auto it22 = find(values.begin(),values.end(),v2.values[i]);
        EXPECT_NE(it21,keys.end()); EXPECT_NE(it22,values.end());

        auto it31 = find(keys.begin(),keys.end(),v3.keys[i]);
        auto it32 = find(values.begin(),values.end(),v3.values[i]);
        EXPECT_NE(it31,keys.end()); EXPECT_NE(it32,values.end());

        auto it41 = find(keys.begin(),keys.end(),v4.keys[i]);
        auto it42 = find(values.begin(),values.end(),v4.values[i]);
        EXPECT_NE(it41,keys.end()); EXPECT_NE(it42,values.end());
    }
    CleanUp(s1,s2,s3,s4);
}

int main(int argc,char*argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
