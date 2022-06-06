#pragma once

// 계약서 / 결재 와 같은 느낌

/// cpu가 사용하는걸  gpu에게 외주를 주는 느낌인데 둘이 사용하는 공간이 완전히 다르다
/// gpu는 ram에 있는걸 일일이 꺼내쓰기 어렵다(멀다)
/// gpu의 공간을 임대해서 사용하겠다는 계약과 같다
/// 그 과정을 확실하게 서명하는 것이 rootsignature
/// 어떤 땅, 어떤 정책을 사용할 것인지를 계약하는 것

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);


	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }


private:
	ComPtr<ID3D12RootSignature> _signature;

};

