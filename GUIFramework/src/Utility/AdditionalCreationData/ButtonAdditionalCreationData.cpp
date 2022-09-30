#include "Core.h"
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

		AdditionalCreationData<ImageButton>::AdditionalCreationData(const wstring& text, const filesystem::path& pathToImage, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType type, const function<void()>& onClick) :
			text(text),
			pathToImage(pathToImage),
			imageWidth(imageWidth),
			imageHeight(imageHeight),
			type(type),
			onClick(onClick)
		{

		}

		AdditionalCreationData<ImageButton>::AdditionalCreationData(const wstring& text, const filesystem::path& pathToImage, uint16_t imageWidth, uint16_t imageHeight, ImageButton::drawingType type, const string& onClickFunctionName, const string& onClickFunctionModule) :
			text(text),
			pathToImage(pathToImage),
			imageWidth(imageWidth),
			imageHeight(imageHeight),
			type(type),
			onClickFunctionName(onClickFunctionName),
			onClickFunctionModule(onClickFunctionModule)
		{

		}

		any AdditionalCreationData<ImageButton>::getData() const
		{
			return make_any<tuple<wstring, filesystem::path, uint16_t, uint16_t, ImageButton::drawingType, function<void()>, string, string>>(text, pathToImage, imageWidth, imageHeight, type, onClick, onClickFunctionName, onClickFunctionModule);
		}
	}
}
