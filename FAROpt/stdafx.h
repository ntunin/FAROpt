// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include "WindowsProcessManager.h"
#include "Utils.h"
#include "ConsoleScreen.h"
#include "OneLimitOptimisationMenuScreen.h"
#include "FullLimitOptimisationMenuScreen.h"
#include "OptimisationScreen.h"
#include "OptimisationEnvirounment.h"
#include "LamdaDirectivityOptimisationScreen.h"
#include "LamdaDirectivityOptimisationAlgoritm.h"
#include "LamdaGainOptimisationAlgoritm.h"
#include "LamdaGainOptimisationScreen.h"
#include "OneLimitOptimisationAlgoritm.h"
#include "OneLimitHGOptimisationAlgoritm.h"
#include "OneLimitHGOptimisationScreen.h"
#include "OneLimitHGSAOptimisationAlgoritm.h"
#include "OneLimitHGSAScreen.h"
#include "OneLimitGradientSAOptimisationAlgoritm.h"
#include "OneLimitGradientOptimisationScreen.h"
#include "OneLimitGradientOptimisationAlgoritm.h"
#include "OneLimitGradientSAOptimisationScreen.h"
#include "FullLimitPowerOptimisationHGSAScreen.h"
#include "FullLimitPowerOptimisationHGSAAlgoritm.h"
#include "FullLimitPowerOptimisationGradientSAScreen.h"
#include "FullLimitPowerOptimisationGradientSAAlgoritm.h"
#include "CheckoutData.h"
#include "CheckProvidedSolutionScreen.h"
#include "LifeCycle.h"
#include "Log.h"
#include "Scanner.h"
#include "ConsoleLog.h"
#include "ConsoleScanner.h"
#include "FileException.h"
#include "OneSourceNecInWritterException.h"
#include "NecOutParser.h"
#include "NecInParser.h"
#include "CacheManager.h"
#include "WindowsCacheManager.h"
#include "Shared.h"
#include "OneSourceNecInWritter.h"
#include "OneSourceThread.h"
#include "AllSourceNecInWritter.h"
#include "AllSourceNecInWritterException.h"
#include "AllSourceThread.h"
#include "NecOutPlotDrawer.h"
#include "PlotWritter.h"
#include "TableValueParser.h"
#include "Complex.h"
#include "ComplexVector.h"
#include "ComplexVectorT.h"
#include "ComplexMatrix.h"
#include "NecOut.h"
#include "NecIn.h"
#include "FileParser.h"
#include "FileStreamHandler.h"
#include "StringHandler.h"
#include "KeywordsHandler.h"
#include "AntenaInputsKeywordsHandler.h"
#include "RadiationKeywordsHandler.h"
#include "FileStructure.h"
#include "NecCommand.h"
#include "CE.h"
#include "CM.h"
#include "GE.h"
#include "EN.h"
#include "EX.h"
#include "FR.h"
#include "GN.h"
#include "GW.h"
#include "GE.h"
#include "PT.h"
#include "RP.h"
#include "CEHandler.h"
#include "CMHandler.h"
#include "ENHandler.h"
#include "EXHandler.h"
#include "FRHandler.h"
#include "GEHandler.h"
#include "GNHandler.h"
#include "GWHandler.h"
#include "PTHandler.h"
#include "RPHandler.h"

#include "TreeMap.h"

// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
