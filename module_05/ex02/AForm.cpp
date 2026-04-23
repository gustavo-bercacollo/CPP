#include "AForm.hpp"
#include "Bureaucrat.hpp"

// 🔹 Construtor padrão (opcional, mas exigido no canônico)
AForm::AForm()
    : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

// 🔹 Construtor principal
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// 🔹 Copy constructor
AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

// 🔹 Operator =
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

// 🔹 Destrutor
AForm::~AForm()
{
}

// 🔹 Getters
std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();

    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.getName()
        << ", signed: " << f.getIsSigned()
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
