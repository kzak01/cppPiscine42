#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <vector>
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock {
	private:
		std::string name;
		std::string title;
		std::vector<ASpell*> spells;

	public:
		Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
			std::cout << name << ": This look..." << std::endl;
		}
		Warlock(const Warlock&) = delete;
		Warlock& operator=(const Warlock&) = delete;
		~Warlock() {
			std::cout << name << ": My job here.." << std::endl;
			for (ASpell* spell : spells) {
				delete spell;
			}
		}

		const std::string& getName() const {return name;}
		const std::string& getTitle() const {return title;}
		void setTitle(const std::string& title) {this->title = title;}

		void introduce() const {
			std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
		}
		void learnSpell(ASpell* spell) {spells.push_back(spell);}
		void forgetSpell(const std::string& spellName) {
			for (auto it = spells.begin(); it != spells.end(); ++it) {
				if ((*it)->getName() == spellName) {
					delete *it;
					spells.erase(it);
					break;
				}
			}
		}
		void launchSpell(const std::string& spellName, const ATarget& target) {
			for (ASpell* spell : spells) {
				if (spell->getName() == spellName) {
					spell->launch(target);
					break;
				}
			}
		}
};

#endif
