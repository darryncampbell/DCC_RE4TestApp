#pragma once

#include "../runtime/CameraRuntime.h"

namespace rho {

namespace CameraRuntime {
    public ref class CCameraMethodResultImpl sealed: public IMethodResult
    {
        rho::apiGenerator::CMethodResult* oResult;
    public:
        CCameraMethodResultImpl(int64 native);

        virtual void set(Platform::String^ res);
        virtual void set(Windows::Foundation::Collections::IVectorView<Platform::String^>^ res);
        virtual void set(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ res);
    };
}

}
