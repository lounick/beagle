/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   beagle/GP/MutationSwapSubtreeConstrainedOp.hpp
 *  \brief  Definition of the class GP::MutationSwapSubtreeConstrainedOp.
 *  \author Christian Gagne <cgagne@gmail.com>
 *  \author Jianjun Hu <hujianju@msu.edu>
 *  \author Marc Parizeau <parizeau@gel.ulaval.ca>
 *  $Revision: 1.9 $
 *  $Date: 2007/08/08 19:26:35 $
 */

#ifndef Beagle_GP_MutationSwapSubtreeConstrainedOp_hpp
#define Beagle_GP_MutationSwapSubtreeConstrainedOp_hpp

#include <string>

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/EC/MutationOp.hpp"
#include "Beagle/Core/UInt.hpp"
#include "Beagle/Core/Float.hpp"
#include "Beagle/Core/Bool.hpp"
#include "Beagle/GP/Context.hpp"
#include "Beagle/GP/Individual.hpp"
#include "Beagle/GP/MutationSwapSubtreeOp.hpp"

namespace Beagle
{
namespace STGP
{

/*!
 *  \brief Constrained GP tree swap subtree mutation operator class.
 *
 *  There is two kind of swap subtree mutation operations: internal mutation and external mutation.
 *  Internal swap subtree mutation is done by using three mutation points, where the 2nd point is 
 *  within the 1st point's subtree, and the 3rd point is within the 2nd point's subtree. The 
 *  exchange is done by 1) exchanging the 2nd point with the 1st point, 2) exchanging the 1st 
 *  point with the 3rd point, and 3) exchanging the 3rd point with the 2nd point. The structure of the 
 *  tree, which is originally 1-2-3, is changed for 2-1-3. The external swap subtree mutation is 
 *  done by exchanging two subtrees of the same individual, where the two subtrees are not within 
 *  the other subtree.
 */
class MutationSwapSubtreeConstrainedOp : public GP::MutationSwapSubtreeOp
{

public:

	//! GP::MutationSwapSubtreeConstrainedOp allocator type.
	typedef AllocatorT<MutationSwapSubtreeConstrainedOp,GP::MutationSwapSubtreeOp::Alloc>
	Alloc;
	//! GP::MutationSwapSubtreeConstrainedOp handle type.
	typedef PointerT<MutationSwapSubtreeConstrainedOp,GP::MutationSwapSubtreeOp::Handle>
	Handle;
	//! GP::MutationSwapSubtreeConstrainedOp bag type.
	typedef ContainerT<MutationSwapSubtreeConstrainedOp,GP::MutationSwapSubtreeOp::Bag>
	Bag;

	explicit MutationSwapSubtreeConstrainedOp(std::string inMutationPbName="gp.mutsst.indpb",
	        std::string inDistribPbName="gp.mutsst.distrpb",
	        std::string inName="GP-MutationSwapSubtreeConstrainedOp");
	virtual ~MutationSwapSubtreeConstrainedOp()
	{ }

	virtual bool mutate(Beagle::Individual& ioIndividual, Beagle::Context& ioContext);

};

}
}

#endif // Beagle_GP_MutationSwapSubtreeConstrainedOp_hpp
