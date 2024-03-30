#include <iostream>
using namespace std;

void printMenu(string menu[], int prices[], int size) {
    cout << "***** 슈니의 라면가게에 오신 것을 환영합니다 *****" << endl << endl;

    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << menu[i] << " (" << prices[i] << "원)" << endl;
    }
    cout << endl;
}

int total(int* quantities, int* prices, int size) {
    int totalPrice = 0;
    for (int i = 0; i < size; ++i) {
        totalPrice += quantities[i] * prices[i];
    }
    return totalPrice;
}

int main() {
    string menu[] = { "일반 라면", "김치 라면", "치즈 라면", "떡 라면", "떡 만두 라면" };
    int prices[] = { 3500, 4000, 4200, 4300, 4500 };
    int size = sizeof(menu) / sizeof(menu[0]);
    int quantities[sizeof(menu) / sizeof(menu[0])] = { 0 };
    do {
        printMenu(menu, prices, size);

        int choice;
        cout << "구매하실 라면 번호를 입력해주세요 (종료는 0) : ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice < 0 || choice > size) {
            cout << "제대로 된 숫자를 입력해 주세요." << endl << endl;
            continue;
        }

        cout << endl;
        cout << menu[choice - 1] << "을(를) 구매하시겠습니까? (Y/N) ";
        char confirm;
        cin >> confirm;

        if (confirm == 'Y') {
            int quantity;
            cout << "구매하실 라면 개수를 입력해주세요 : ";
            cin >> quantity;

            quantities[choice - 1] += quantity;

            cout << endl;
            cout << menu[choice - 1] << " " << quantity << "개를 구매하셨습니다." << endl;
            cout << "가격은 " << quantity * prices[choice - 1] << "원입니다." << endl << endl;
        }
        else {
        }

    } while (true);

    cout << "총 가격은 " << total(quantities, prices, size) << "원입니다." << endl;

    return 0;
}