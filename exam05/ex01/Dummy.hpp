#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget {
	public:
		Dummy() : ATarget("Target Practice Dummy") {}

		Dummy* clone() const override {return new Dummy(*this);}
};

#endif