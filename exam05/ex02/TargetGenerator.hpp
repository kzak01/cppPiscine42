#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <vector>
# include "ATarget.hpp"

class TargetGenerator {
	private:
		std::vector<ATarget*> targetTypes;

	public:
		TargetGenerator() {}
		TargetGenerator(const TargetGenerator&) = delete;
		TargetGenerator& operator=(const TargetGenerator&) = delete;
		~TargetGenerator() {
			for (ATarget* target : targetTypes) {
				delete target;
			}
		}

		void learnTargetType(ATarget* targetType) {targetTypes.push_back(targetType->clone());}
		void forgetTargetType(const std::string& targetType) {
			for (auto it = targetTypes.begin(); it != targetTypes.end(); ++it) {
				if ((*it)->getType() == targetType) {
					delete *it;
					targetTypes.erase(it);
					break;
				}
			}
		}
		ATarget* createTarget(const std::string& targetType) const {
			for (ATarget* target : targetTypes) {
				if (target->getType() == targetType) {
					return target->clone();
				}
			}
			return nullptr;
		}
};

#endif
