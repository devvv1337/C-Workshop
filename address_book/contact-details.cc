#include "contact-details.hh"

ContactDetails::ContactDetails(const std::string& telephone_number,
                               const std::string& personal_email)
    : number(telephone_number)
    , email(personal_email)
{
    for (auto c : number)
    {
        if (!std::isdigit(c))
        {
            throw std::invalid_argument("Incorrect number.");
        }
    }

    if (email.find('@') == std::string::npos)
    {
        throw std::invalid_argument("Incorrect email.");
    }
}

std::ostream& operator<<(std::ostream& os,
                         const ContactDetails& contact_details)
{
    os << contact_details.number << ", " << contact_details.email << std::endl;
    return os;
}
