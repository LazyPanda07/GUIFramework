#include "ButtonAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<Button>::AdditionalCreationData(const wstring text, const function<void()>& onClick) :
			text(text),
			onClick(onClick)
		{

		}

		AdditionalCreationData<Button>::AdditionalCreationData(const wstring text, const string& onClickFunctionName, const string& onClickFunctionModule) :
			text(text),
			onClickFunctionName(onClickFunctionName),
			onClickFunctionModule(onClickFunctionModule)
		{
			
		}

		any AdditionalCreationData<Button>::getData() const
		{
			return make_any<tuple<wstring, function<void()>, string, string>>(text, onClick, onClickFunctionName, onClickFunctionModule);
		}

		AdditionalCreationData<CheckBox>::AdditionalCreationData(const wstring text, const function<void()>& onCheck, const function<void()>& onClear, const function<void()>& onClick) :
			text(text),
			onCheck(onCheck),
			onClear(onClear),
			onClick(onClick)
		{

		}

		AdditionalCreationData<CheckBox>::AdditionalCreationData(const wstring text, const string& onCheckFunctionName, const string& onCheckFunctionModule, const string& onClearFunctionName, const string& onClearFunctionModule, const string& onClickFunctionName, const string& onClickFunctionModule) :
			text(text),
			onCheckFunctionName(onCheckFunctionName),
			onCheckFunctionModule(onCheckFunctionModule),
			onClearFunctionName(onCheckFunctionName),
			onClearFunctionModule(onCheckFunctionModule),
			onClickFunctionName(onCheckFunctionName),
			onClickFunctionModule(onCheckFunctionModule)
		{
			
		}

		any AdditionalCreationData<CheckBox>::getData() const
		{
			return make_any<tuple<wstring, function<void()>, function<void()>, function<void()>, string, string, string, string, string, string>>(text, onCheck, onClear, onClick, onCheckFunctionName, onCheckFunctionModule, onClearFunctionName, onClearFunctionModule, onClickFunctionName, onClickFunctionModule);
		}

		AdditionalCreationData<ImageButton>::AdditionalCreationData(const wstring& text, const filesystem::path& pathToImage, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType dType, ImageButton::imageType iType, const function<void()>& onClick) :
			text(text),
			pathToImage(pathToImage),
			imageResource(NULL),
			imageWidth(imageWidth),
			imageHeight(imageHeight),
			dType(dType),
			iType(iType),
			onClick(onClick)
		{

		}

		AdditionalCreationData<ImageButton>::AdditionalCreationData(const wstring& text, const filesystem::path& pathToImage, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType dType, ImageButton::imageType iType, const string& onClickFunctionName, const string& onClickFunctionModule) :
			text(text),
			pathToImage(pathToImage),
			imageResource(NULL),
			imageWidth(imageWidth),
			imageHeight(imageHeight),
			dType(dType),
			iType(iType),
			onClickFunctionName(onClickFunctionName),
			onClickFunctionModule(onClickFunctionModule)
		{

		}

		AdditionalCreationData<ImageButton>::AdditionalCreationData(const wstring& text, uint32_t imageResource, const string& resourceModuleName, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType dType, ImageButton::imageType iType, const function<void()>& onClick) :
			text(text),
			resourceModuleName(resourceModuleName),
			imageResource(imageResource),
			imageWidth(imageWidth),
			imageHeight(imageHeight),
			dType(dType),
			iType(iType),
			onClick(onClick)
		{

		}

		AdditionalCreationData<ImageButton>::AdditionalCreationData(const wstring& text, uint32_t imageResource, const string& resourceModuleName, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType dType, ImageButton::imageType iType, const string& onClickFunctionName, const string& onClickFunctionModule) :
			text(text),
			resourceModuleName(resourceModuleName),
			imageResource(imageResource),
			imageWidth(imageWidth),
			imageHeight(imageHeight),
			dType(dType),
			iType(iType),
			onClickFunctionName(onClickFunctionName),
			onClickFunctionModule(onClickFunctionModule)
		{

		}

		any AdditionalCreationData<ImageButton>::getData() const
		{
			return make_any
				<tuple<wstring, filesystem::path, uint32_t, string, uint16_t, uint16_t, ImageButton::drawingType, ImageButton::imageType, function<void()>, string, string>>
				(text, pathToImage, imageResource, resourceModuleName, imageWidth, imageHeight, dType, iType, onClick, onClickFunctionName, onClickFunctionModule);
		}
	}
}
