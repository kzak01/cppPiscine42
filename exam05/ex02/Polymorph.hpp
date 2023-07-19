#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		Polymorph() : ASpell("Polymorph", "turned into a critter") {}

		Polymorph* clone() const override {return new Polymorph(*this);}
};

#endif