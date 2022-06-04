#pragma once
class Engine
{
public:
	void Init(const WindowInfo& info);
	void Render();

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);
private:
	//�׷��� ȭ�� ũ�� ����
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	//�ʱ�ȭ�� �ʿ��� �κе�
	shared_ptr<class Device> _device; //gpu�� ������ �� ���, �ٽ�
	shared_ptr<class CommandQueue> _cmdQueue; //gpu�� ��û ���� �� ��Ƽ� ������ ���� ����
	shared_ptr<class SwapChain> _swapChain; //���� ���۸� �뵵


};
