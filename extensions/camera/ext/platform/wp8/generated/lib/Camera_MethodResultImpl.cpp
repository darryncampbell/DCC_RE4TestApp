#include "Camera_MethodResultImpl.h"

namespace rho {

using namespace CameraRuntime;

CCameraMethodResultImpl::CCameraMethodResultImpl(int64 native):
    oResult((rho::apiGenerator::CMethodResult*)native)
{
}

void CCameraMethodResultImpl::set(Platform::String^ res)
{
    oResult->set(rho::common::convertToStringW(res->Data()));
}

void CCameraMethodResultImpl::set(Windows::Foundation::Collections::IVectorView<Platform::String^>^ res)
{
    // TODO: implement types/class conversion
}

void CCameraMethodResultImpl::set(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ res)
{
    // TODO: implement types/class conversion
}


}
