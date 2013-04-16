#include "common/RhodesApp.h"
#include "../../wp8/rhoruntime/common/RhoConvertWP8.h"
#include "../../../../shared/generated/cpp/CameraBase.h"
#include "Camera_MethodResultImpl.h"

using namespace rho::apiGenerator;

namespace rho {

using namespace CameraRuntime;

class CCameraImpl: public CCameraBase
{
    ICameraImpl^ _runtime;
public:
    CCameraImpl(const rho::String& strID): CCameraBase()
    {
        // TODO: implement implementation constructor
    }

    virtual void registerRuntime(ICameraImpl^ runtime)
    {
        _runtime = runtime;
    }

    virtual void getCameraType(CMethodResult& oResult)
    {
        _runtime->getCameraType(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getMaxWidth(CMethodResult& oResult)
    {
        _runtime->getMaxWidth(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getMaxHeight(CMethodResult& oResult)
    {
        _runtime->getMaxHeight(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getDesiredWidth(CMethodResult& oResult)
    {
        _runtime->getDesiredWidth(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setDesiredWidth(int desiredWidth, CMethodResult& oResult)
    {
        _runtime->setDesiredWidth(desiredWidth, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getDesiredHeight(CMethodResult& oResult)
    {
        _runtime->getDesiredHeight(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setDesiredHeight(int desiredHeight, CMethodResult& oResult)
    {
        _runtime->setDesiredHeight(desiredHeight, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getCompressionFormat(CMethodResult& oResult)
    {
        _runtime->getCompressionFormat(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setCompressionFormat(const rho::String& compressionFormat, CMethodResult& oResult)
    {
        Platform::String^ _compressionFormat = rho::convertStringWP8(compressionFormat);
        _runtime->setCompressionFormat(_compressionFormat, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getOutputFormat(CMethodResult& oResult)
    {
        _runtime->getOutputFormat(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setOutputFormat(const rho::String& outputFormat, CMethodResult& oResult)
    {
        Platform::String^ _outputFormat = rho::convertStringWP8(outputFormat);
        _runtime->setOutputFormat(_outputFormat, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getColorModel(CMethodResult& oResult)
    {
        _runtime->getColorModel(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setColorModel(const rho::String& colorModel, CMethodResult& oResult)
    {
        Platform::String^ _colorModel = rho::convertStringWP8(colorModel);
        _runtime->setColorModel(_colorModel, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getEnableEditing(CMethodResult& oResult)
    {
        _runtime->getEnableEditing(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setEnableEditing(bool enableEditing, CMethodResult& oResult)
    {
        _runtime->setEnableEditing(enableEditing, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getFlashMode(CMethodResult& oResult)
    {
        _runtime->getFlashMode(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setFlashMode(const rho::String& flashMode, CMethodResult& oResult)
    {
        Platform::String^ _flashMode = rho::convertStringWP8(flashMode);
        _runtime->setFlashMode(_flashMode, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getSaveToSharedGallery(CMethodResult& oResult)
    {
        _runtime->getSaveToSharedGallery(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setSaveToSharedGallery(bool saveToSharedGallery, CMethodResult& oResult)
    {
        _runtime->setSaveToSharedGallery(saveToSharedGallery, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getCaptureSound(CMethodResult& oResult)
    {
        _runtime->getCaptureSound(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setCaptureSound(const rho::String& captureSound, CMethodResult& oResult)
    {
        Platform::String^ _captureSound = rho::convertStringWP8(captureSound);
        _runtime->setCaptureSound(_captureSound, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getPreviewLeft(CMethodResult& oResult)
    {
        _runtime->getPreviewLeft(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setPreviewLeft(int previewLeft, CMethodResult& oResult)
    {
        _runtime->setPreviewLeft(previewLeft, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getPreviewTop(CMethodResult& oResult)
    {
        _runtime->getPreviewTop(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setPreviewTop(int previewTop, CMethodResult& oResult)
    {
        _runtime->setPreviewTop(previewTop, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getPreviewWidth(CMethodResult& oResult)
    {
        _runtime->getPreviewWidth(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setPreviewWidth(int previewWidth, CMethodResult& oResult)
    {
        _runtime->setPreviewWidth(previewWidth, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getPreviewHeight(CMethodResult& oResult)
    {
        _runtime->getPreviewHeight(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setPreviewHeight(int previewHeight, CMethodResult& oResult)
    {
        _runtime->setPreviewHeight(previewHeight, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void takePicture(const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult)
    {
        Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ _propertyMap = rho::convertHashWP8(propertyMap);
        _runtime->takePicture(_propertyMap, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getProperty(const rho::String& propertyName, CMethodResult& oResult)
    {
        Platform::String^ _propertyName = rho::convertStringWP8(propertyName);
        _runtime->getProperty(_propertyName, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getProperties(const rho::Vector<rho::String>& arrayofNames, CMethodResult& oResult)
    {
        Windows::Foundation::Collections::IVectorView<Platform::String^>^ _arrayofNames = rho::convertArrayWP8(arrayofNames);
        _runtime->getProperties(_arrayofNames, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getAllProperties(CMethodResult& oResult)
    {
        _runtime->getAllProperties(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setProperty(const rho::String& propertyName, const rho::String& propertyValue, CMethodResult& oResult)
    {
        Platform::String^ _propertyName = rho::convertStringWP8(propertyName);
        Platform::String^ _propertyValue = rho::convertStringWP8(propertyValue);
        _runtime->setProperty(_propertyName, _propertyValue, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void setProperties(const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult)
    {
        Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ _propertyMap = rho::convertHashWP8(propertyMap);
        _runtime->setProperties(_propertyMap, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void clearAllProperties(CMethodResult& oResult)
    {
        _runtime->clearAllProperties(ref new CCameraMethodResultImpl((int64)&oResult));
    }
};

class CCameraSingleton: public CCameraSingletonBase
{
    ICameraSingletonImpl^ _runtime;
public:
    ~CCameraSingleton(){}

    virtual void registerRuntime(ICameraSingletonImpl^ runtime)
    {
        _runtime = runtime;
    }

    virtual void enumerate(CMethodResult& oResult)
    {
        _runtime->enumerate(ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void getCameraByType(const rho::String& cameraType, CMethodResult& oResult)
    {
        Platform::String^ _cameraType = rho::convertStringWP8(cameraType);
        _runtime->getCameraByType(_cameraType, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void choosePicture(const rho::Hashtable<rho::String, rho::String>& propertyMap, CMethodResult& oResult)
    {
        Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ _propertyMap = rho::convertHashWP8(propertyMap);
        _runtime->choosePicture(_propertyMap, ref new CCameraMethodResultImpl((int64)&oResult));
    }

    virtual void saveImageToDeviceGallery(const rho::String& pathToImage, CMethodResult& oResult)
    {
        Platform::String^ _pathToImage = rho::convertStringWP8(pathToImage);
        _runtime->saveImageToDeviceGallery(_pathToImage, ref new CCameraMethodResultImpl((int64)&oResult));
    }


    virtual rho::String getDefaultID(){return "1";} // TODO: implement getDefaultID
    virtual rho::String getInitialDefaultID(){return "1";} // TODO: implement getInitialDefaultID
    virtual void setDefaultID(const rho::String& strID){} // TODO: implement setDefaultID
    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor){} // TODO: implement addCommandToQueue
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor){} // TODO: implement callCommandInThread
};

class CCameraFactory: public CCameraFactoryBase
{
    ~CCameraFactory(){}
    virtual ICameraSingleton* createModuleSingleton();
    virtual ICamera* createModuleByID(const rho::String& strID);
};

ICamera* CCameraFactory::createModuleByID(const rho::String& strID)
{
    return new CCameraImpl(strID);
}

ICameraSingleton* CCameraFactory::createModuleSingleton()
{
    return new CCameraSingleton();
}

}

extern "C" void Init_Camera()
{
    rho::CCameraFactory::setInstance( new rho::CCameraFactory() );
    rho::Init_Camera_API();

    RHODESAPP().getExtManager().requireRubyFile("RhoCameraApi");
}
