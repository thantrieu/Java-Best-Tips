#include <iostream>
using namespace std;

// vẽ đường viền hình vuông: i == 1 || j == 1 || i == h || j == h 
// sau đó vẽ đường chéo chính, phụ: i == j || i + j == h + 1
// được hình như trong mô tả sau, h = 6:
// * * * * * *
// * *     * *
// *   * *   *
// *   * *   *
// * *     * *
// * * * * * *

void drawRect(int h) {
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			if (i == 1 || j == 1 || i == h || j == h
				|| i == j || i + j == h + 1) {
				cout << " * ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}
}

int main() {
	int h;
	cout << "Nhap vao canh hinh vuong: ";
	cin >> h;
	if (h > 0) {
		drawRect(h);
	}
	else {
		cout << "Canh khong hop le. Vui long kiem tra lai!\n";
	}
	
	return 0;
}