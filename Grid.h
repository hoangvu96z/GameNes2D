#pragma once
#include <vector>
#include "Cell.h"

class Grid
{
	//Thể hiện duy nhất của Grid
	static Grid* _instance;

	//Chiều rộng của map
	int mapWidth;

	//Chiều cao của map
	int mapHeight;
	
	//Số cột của grid
	int cols;
	int rows;
	
	//Danh sách các Cell trong Grid. 
	//Mảng 2 chiều với kích thước mỗi Cell bằng 1/2 chiều dài và 1/2 chiều rộng
	//Kích thước của listCells phụ thuộc vào cols và rows
	std::vector<std::vector<Cell*>> listCells;

public:
	//CGrid(int map_width, int map_height);
	void InitGrid(int map_width, int map_height);
	~Grid();

	//Lấy thể hiện duy nhất của CGrid
	static Grid* GetInstance();

	//Thêm một ObjectCell vào Cell
	void AddToUnKnownCell(ObjectCell* objectCell);
	void AddToKnownCell(ObjectCell* objectCell, int col, int row);
	
	//Lấy các Object gán vào từng list phù hợp
	//void GetListObject(std::vector<ObjectCell*>& listObjectCells, std::vector<LPGAMEOBJECT>& listObjects);

	//Cập nhật một ObjectCell dựa vào tọa độ của GameObject và tọa độ Camera
	void UpdateObjectCell(ObjectCell* unit, float x, float y);


	//Cập nhật Grid
	void Update(std::vector<ObjectCell*>& listObjectCells);

	// lấy tất cả các ObjectCell* nằm trong vùng Camera để Update và Render
	std::vector<ObjectCell*> GetObjectCell();


	void ShowSizeCells();

	//Xóa tất cả cell trong Grid
	void Clear();
};

