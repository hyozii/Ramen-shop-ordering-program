#include <iostream>
using namespace std;

void printMenu(string menu[], int prices[], int size) {
    cout << "***** ������ ��鰡�Կ� ���� ���� ȯ���մϴ� *****" << endl << endl;

    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << menu[i] << " (" << prices[i] << "��)" << endl;
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
    string menu[] = { "�Ϲ� ���", "��ġ ���", "ġ�� ���", "�� ���", "�� ���� ���" };
    int prices[] = { 3500, 4000, 4200, 4300, 4500 };
    int size = sizeof(menu) / sizeof(menu[0]);
    int quantities[sizeof(menu) / sizeof(menu[0])] = { 0 };
    do {
        printMenu(menu, prices, size);

        int choice;
        cout << "�����Ͻ� ��� ��ȣ�� �Է����ּ��� (����� 0) : ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice < 0 || choice > size) {
            cout << "����� �� ���ڸ� �Է��� �ּ���." << endl << endl;
            continue;
        }

        cout << endl;
        cout << menu[choice - 1] << "��(��) �����Ͻðڽ��ϱ�? (Y/N) ";
        char confirm;
        cin >> confirm;

        if (confirm == 'Y') {
            int quantity;
            cout << "�����Ͻ� ��� ������ �Է����ּ��� : ";
            cin >> quantity;

            quantities[choice - 1] += quantity;

            cout << endl;
            cout << menu[choice - 1] << " " << quantity << "���� �����ϼ̽��ϴ�." << endl;
            cout << "������ " << quantity * prices[choice - 1] << "���Դϴ�." << endl << endl;
        }
        else {
        }

    } while (true);

    cout << "�� ������ " << total(quantities, prices, size) << "���Դϴ�." << endl;

    return 0;
}