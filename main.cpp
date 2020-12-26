#include <iostream>
#include <vector>
#include <random>
#include <thread>

using namespace std;

vector<vector<string>> members {{"杨芬","董姐","小琼"},{"辉哥","黄何","刘丹"},{"睿迪","小龙","春林"},{"波波","杨康","盛凯"},{"皓天","匡力","范伟峰"},{"杨宝","郑大叔","康冠"}};

void getResult() {
    vector<string> aGroup;
    vector<string> bGroup;
    vector<string> cGroup;

    default_random_engine random(time(NULL));
    std::uniform_int_distribution<int> dis(0, 2);
    std::uniform_int_distribution<int> dis2(0, 1);

    for(int i = 0; i < members.size(); i++) {
        //int r = 0 + (rand() % 3);
        int r = dis(random);

        int times = 0;
        while (r == 1 && times < 10) {
            r = dis(random);
            times++;
        }
        //cout << r << endl;

        aGroup.push_back(members[i][r]);

        vector<int> afterRand;
        for (int j = 0; j < 3; j++) {
            if (j != r) {
                afterRand.push_back(j);
            }
        }

        //int rr = 0 + (rand() % 1);
        int rr = dis2(random);
        //cout << rr << endl;
        bGroup.push_back(members[i][afterRand[rr]]);

        for (int ii = 0; ii < 2; ii++) {
            if (ii != rr) {
                //cout << ii << endl;
                cGroup.push_back(members[i][afterRand[ii]]);
            }
        }
    }

    cout << "A: " ;
    for (int i = 0; i < aGroup.size(); i++) {
        cout << aGroup[i] << " " ;
    }
    cout << endl;

    cout << "B: " ;
    for (int i = 0; i < bGroup.size(); i++) {
        cout << bGroup[i] << " " ;
    }
    cout << endl;

    cout << "C: " ;
    for (int i = 0; i < cGroup.size(); i++) {
        cout << cGroup[i] << " " ;
    }
    cout << endl;
}

int main() {
    getResult();
}
