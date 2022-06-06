#pragma once

// ��༭ / ���� �� ���� ����

/// cpu�� ����ϴ°�  gpu���� ���ָ� �ִ� �����ε� ���� ����ϴ� ������ ������ �ٸ���
/// gpu�� ram�� �ִ°� ������ �������� ��ƴ�(�ִ�)
/// gpu�� ������ �Ӵ��ؼ� ����ϰڴٴ� ���� ����
/// �� ������ Ȯ���ϰ� �����ϴ� ���� rootsignature
/// � ��, � ��å�� ����� �������� ����ϴ� ��

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);


	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }


private:
	ComPtr<ID3D12RootSignature> _signature;

};

