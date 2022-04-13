#pragma once
class ObjectCell
{
	//toa do cua objectcell (trong game)
	float x;
	float y;

public:
	//Khởi tạo ObjecCell
	//Chưa biết object nằm ở đâu
	ObjectCell(float x, float y);

	//Đã biết vị trí của object
	ObjectCell(float x, float y, int colCell, int rowCell);


	//Update theo tọa độ của CGameObject
	//Tức là object game mà CObject này đang nắm giữ
	void Update(float x, float y);



	//Lấy object nằm trong CObjectCell naỳ
	//LPGAMEOBJECT GetObj() { return this->obj; }


	//GETTER
	float GetX() { return x; }
	float GetY() { return y; }

	//SETTER
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
};

