// CameraRuntime.cpp
#include "CameraRuntime.h"

using namespace Platform;
using namespace rho::apiGenerator;

namespace rho {

using namespace CameraRuntime;

CameraRuntimeComponent::CameraRuntimeComponent(ICameraImpl^ impl):
    _impl(impl)
{
    // TODO: implement runtime component constructor
}

CameraSingletonComponent::CameraSingletonComponent(ICameraSingletonImpl^ impl):
    _impl(impl)
{
    // TODO: implement singleton component constructor
}

void CameraRuntimeComponent::getCameraType(IMethodResult^ oResult)
{
    _impl->getCameraType(oResult);
}

void CameraRuntimeComponent::getMaxWidth(IMethodResult^ oResult)
{
    _impl->getMaxWidth(oResult);
}

void CameraRuntimeComponent::getMaxHeight(IMethodResult^ oResult)
{
    _impl->getMaxHeight(oResult);
}

void CameraRuntimeComponent::getDesiredWidth(IMethodResult^ oResult)
{
    _impl->getDesiredWidth(oResult);
}

void CameraRuntimeComponent::setDesiredWidth(int desiredWidth, IMethodResult^ oResult)
{
    _impl->setDesiredWidth(desiredWidth, oResult);
}

void CameraRuntimeComponent::getDesiredHeight(IMethodResult^ oResult)
{
    _impl->getDesiredHeight(oResult);
}

void CameraRuntimeComponent::setDesiredHeight(int desiredHeight, IMethodResult^ oResult)
{
    _impl->setDesiredHeight(desiredHeight, oResult);
}

void CameraRuntimeComponent::getCompressionFormat(IMethodResult^ oResult)
{
    _impl->getCompressionFormat(oResult);
}

void CameraRuntimeComponent::setCompressionFormat(Platform::String^ compressionFormat, IMethodResult^ oResult)
{
    _impl->setCompressionFormat(compressionFormat, oResult);
}

void CameraRuntimeComponent::getOutputFormat(IMethodResult^ oResult)
{
    _impl->getOutputFormat(oResult);
}

void CameraRuntimeComponent::setOutputFormat(Platform::String^ outputFormat, IMethodResult^ oResult)
{
    _impl->setOutputFormat(outputFormat, oResult);
}

void CameraRuntimeComponent::getColorModel(IMethodResult^ oResult)
{
    _impl->getColorModel(oResult);
}

void CameraRuntimeComponent::setColorModel(Platform::String^ colorModel, IMethodResult^ oResult)
{
    _impl->setColorModel(colorModel, oResult);
}

void CameraRuntimeComponent::getEnableEditing(IMethodResult^ oResult)
{
    _impl->getEnableEditing(oResult);
}

void CameraRuntimeComponent::setEnableEditing(bool enableEditing, IMethodResult^ oResult)
{
    _impl->setEnableEditing(enableEditing, oResult);
}

void CameraRuntimeComponent::getFlashMode(IMethodResult^ oResult)
{
    _impl->getFlashMode(oResult);
}

void CameraRuntimeComponent::setFlashMode(Platform::String^ flashMode, IMethodResult^ oResult)
{
    _impl->setFlashMode(flashMode, oResult);
}

void CameraRuntimeComponent::getSaveToSharedGallery(IMethodResult^ oResult)
{
    _impl->getSaveToSharedGallery(oResult);
}

void CameraRuntimeComponent::setSaveToSharedGallery(bool saveToSharedGallery, IMethodResult^ oResult)
{
    _impl->setSaveToSharedGallery(saveToSharedGallery, oResult);
}

void CameraRuntimeComponent::getCaptureSound(IMethodResult^ oResult)
{
    _impl->getCaptureSound(oResult);
}

void CameraRuntimeComponent::setCaptureSound(Platform::String^ captureSound, IMethodResult^ oResult)
{
    _impl->setCaptureSound(captureSound, oResult);
}

void CameraRuntimeComponent::getPreviewLeft(IMethodResult^ oResult)
{
    _impl->getPreviewLeft(oResult);
}

void CameraRuntimeComponent::setPreviewLeft(int previewLeft, IMethodResult^ oResult)
{
    _impl->setPreviewLeft(previewLeft, oResult);
}

void CameraRuntimeComponent::getPreviewTop(IMethodResult^ oResult)
{
    _impl->getPreviewTop(oResult);
}

void CameraRuntimeComponent::setPreviewTop(int previewTop, IMethodResult^ oResult)
{
    _impl->setPreviewTop(previewTop, oResult);
}

void CameraRuntimeComponent::getPreviewWidth(IMethodResult^ oResult)
{
    _impl->getPreviewWidth(oResult);
}

void CameraRuntimeComponent::setPreviewWidth(int previewWidth, IMethodResult^ oResult)
{
    _impl->setPreviewWidth(previewWidth, oResult);
}

void CameraRuntimeComponent::getPreviewHeight(IMethodResult^ oResult)
{
    _impl->getPreviewHeight(oResult);
}

void CameraRuntimeComponent::setPreviewHeight(int previewHeight, IMethodResult^ oResult)
{
    _impl->setPreviewHeight(previewHeight, oResult);
}

void CameraSingletonComponent::enumerate(IMethodResult^ oResult)
{
    _impl->enumerate(oResult);
}

void CameraSingletonComponent::getCameraByType(Platform::String^ cameraType, IMethodResult^ oResult)
{
    _impl->getCameraByType(cameraType, oResult);
}

void CameraRuntimeComponent::takePicture(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult)
{
    _impl->takePicture(propertyMap, oResult);
}

void CameraSingletonComponent::choosePicture(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult)
{
    _impl->choosePicture(propertyMap, oResult);
}

void CameraSingletonComponent::saveImageToDeviceGallery(Platform::String^ pathToImage, IMethodResult^ oResult)
{
    _impl->saveImageToDeviceGallery(pathToImage, oResult);
}

void CameraRuntimeComponent::getProperty(Platform::String^ propertyName, IMethodResult^ oResult)
{
    _impl->getProperty(propertyName, oResult);
}

void CameraRuntimeComponent::getProperties(Windows::Foundation::Collections::IVectorView<Platform::String^>^ arrayofNames, IMethodResult^ oResult)
{
    _impl->getProperties(arrayofNames, oResult);
}

void CameraRuntimeComponent::getAllProperties(IMethodResult^ oResult)
{
    _impl->getAllProperties(oResult);
}

void CameraRuntimeComponent::setProperty(Platform::String^ propertyName, Platform::String^ propertyValue, IMethodResult^ oResult)
{
    _impl->setProperty(propertyName, propertyValue, oResult);
}

void CameraRuntimeComponent::setProperties(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult)
{
    _impl->setProperties(propertyMap, oResult);
}

void CameraRuntimeComponent::clearAllProperties(IMethodResult^ oResult)
{
    _impl->clearAllProperties(oResult);
}

}
