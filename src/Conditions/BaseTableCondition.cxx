#include "Conditions/SimpleTableCondition.h"
#include <algorithm>

namespace ldmx {
    
    std::size_t BaseTableCondition::findKey(unsigned int id) const {
        unsigned int effid=id&idMask_;
	std::vector<unsigned int>::const_iterator ptr=std::lower_bound(keys_.begin(), keys_.end(), effid);
	if (ptr==keys_.end() || *ptr!=effid) return keys_.size();
	else return std::distance(keys_.begin(),ptr);
    }
    
    std::size_t BaseTableCondition::findKeyInsert(unsigned int id) const {
        unsigned int effid=id&idMask_;
	std::vector<unsigned int>::const_iterator ptr=std::lower_bound(keys_.begin(), keys_.end(), effid);
	return std::distance(keys_.begin(),ptr);
    }

    
}

    