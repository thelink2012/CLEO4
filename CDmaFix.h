#pragma once
#include "CCodeInjector.h"

namespace CLEO
{
	class CDmaFix : public VInjectible
	{
	public:
		virtual void Inject(CCodeInjector& inj);
	};
}