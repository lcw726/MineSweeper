#pragma once
using namespace System;

class CMine{
private: int roundMineNo;
		 bool mine;
		 bool mark;
		 bool click;
public:
	CMine(){
		roundMineNo = 0;
		mine = false;
	}
	CMine(bool b){
		roundMineNo = 0;
		setMine(b);
		setClicked(false);
		setMarked(false);
	}
	~CMine(){}
	void plusRoundMineNo(){
		roundMineNo++;
	}
	int getRoundMineNo(){
		return roundMineNo;
	}
	void setMine(bool b){
		mine = b;
	}
	int isMine(){
		return mine;
	}
	void setMarked(bool b){
		mark = b;
	}
	int isMarked(){
		return mark;
	}
	void setClicked(bool b){
		click = b;
	}
	int isClicked(){
		return click;
	}

};