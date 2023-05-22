#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	friend std::ostream& operator<<(std::ostream& couter, const Fraction& p)
	{
		if (p.numerator_ == p.denominator_)
		{
			couter << 1;
		}
		else if (p.denominator_ == 1)
		{
			couter << p.numerator_;
		}
		else
		{
			couter << p.numerator_ << "/" << p.denominator_;
		}
		return couter;
	}
	Fraction operator+(Fraction p)
	{
		int numerator1_ = numerator_ * p.denominator_ + denominator_ * p.numerator_;
		int denomirator1_ = denominator_ * p.denominator_;
		return Fraction(numerator1_, denomirator1_);
	}
	Fraction operator-(Fraction p)
	{
		int numerator1_ = numerator_ * p.denominator_ - denominator_ * p.numerator_;
		int denomirator1_ = denominator_ * p.denominator_;
		return Fraction(numerator1_, denomirator1_);
	}
	Fraction operator*(Fraction p)
	{
		int numerator1_ = numerator_ * p.numerator_;
		int denomirator1_ = denominator_ * p.denominator_;
		return Fraction(numerator1_, denomirator1_);
	}
	Fraction operator/(Fraction p)
	{
		int numerator1_ = numerator_ * p.denominator_;
		int denomirator1_ = denominator_ * p.numerator_;
		return Fraction(numerator1_, denomirator1_);
	}
	Fraction operator-() { return Fraction( - numerator_,denominator_); }
	Fraction operator++() { numerator_ += denominator_; return Fraction(numerator_,denominator_); }
	Fraction operator++(int)
	{
		Fraction temp = *this;
		++* this;
		return temp;
	}
	Fraction operator--() { numerator_ -= denominator_; return Fraction(numerator_, denominator_); }
	Fraction operator--(int)
	{
		Fraction temp = *this;
		--* this;
		return temp;
	}
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	static Fraction reduction(Fraction p)
	{
		int a;
		if (abs(p.numerator_) > abs(p.denominator_))
		{
			a = abs(p.denominator_);
		}
		else
		{
			a = abs(p.numerator_);
		}
		int i = 2;
		while (i <= a)
		{
			if (p.numerator_ % i == 0 && p.denominator_ % i == 0)
			{
				p.numerator_ /= i;
				p.denominator_ /= i;
				i = 2;
			}
			else
			{
				i++;
			}
		}
		return p;
	}
};

int main()
{
	int a, b, a1, b1;
	std::cout << "Enter numerator of first fraction: ";
	std::cin >> a;
	std::cout << "Enter denominator of first fraction: ";
	std::cin >> b;
	std::cout << "Enter numerator of second fraction: ";
	std::cin >> a1;
	std::cout << "Enter denominator of second fraction: ";
	std::cin >> b1;
	Fraction p1(a, b);
	Fraction p2(a1, b1);
	std::cout << p1 << " + " << p2 << " = " << Fraction::reduction(p1 + p2) << std::endl;
	std::cout << p1 << " - " << p2 << " = " << Fraction::reduction(p1 - p2) << std::endl;
	std::cout << p1 << " * " << p2 << " = " << Fraction::reduction(p1 * p2) << std::endl;
	std::cout << p1 << " / " << p2 << " = " << Fraction::reduction(p1 / p2) << std::endl;
	std::cout << "++" << p1 << " * " << p2 << " = ";
	std::cout << Fraction::reduction((++p1) * p2) << std::endl;
	std::cout << "Value of first fraction: " << Fraction::reduction(p1) << std::endl;
	std::cout << p1 << "--" << " * " << p2 << " = ";
	std::cout << Fraction::reduction((p1--) * p2) << std::endl;
	std::cout << "Value of first fraction: " << Fraction::reduction(p1) << std::endl;
	return 0;
}