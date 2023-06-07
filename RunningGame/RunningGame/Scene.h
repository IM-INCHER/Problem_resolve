#pragma once

class Scene
{
private:

protected:
	bool isGame = false;

public:
	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual void Release() {}

	void ExitGame() { isGame = true; }
	bool GetIsGame() { return isGame; }
};

