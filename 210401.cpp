//abstract factory

#include <iostream>


class IMinutesPackage
{
  public:
    virtual ~IMinutesPackage() = 0;
};
IMinutesPackage::~IMinutesPackage(){  };

class LowMinutesPackage : public IMinutesPackage {  };
class LargeMinutesPackage : public IMinutesPackage {  };


class ISMSPackage
{
  public:
    virtual ~ISMSPackage() = 0;
};
ISMSPackage::~ISMSPackage(){  };

class LowSMSPackage : public ISMSPackage {  };
class LargeSMSPackage : public ISMSPackage {  };


class AgreementFactory
{
  public:
    virtual ~AgreementFactory(){}
    virtual IMinutesPackage *createMinutesPackage() = 0;
    virtual ISMSPackage *createSMSPackage() = 0;
};

class EconomicAgreementFactory : public AgreementFactory
{
  public:
    IMinutesPackage *createMinutesPackage(){ return new LowMinutesPackage(); }
    ISMSPackage *createSMSPackage(){ return new LowSMSPackage(); }
};

class GoldAgreementFactory : public AgreementFactory
{
  public:
    IMinutesPackage *createMinutesPackage(){ return new LargeMinutesPackage(); }
    ISMSPackage *createSMSPackage(){ return new LargeSMSPackage(); }
};

class CheaperMinutesAgreementFactory : public AgreementFactory
{
  public:
    IMinutesPackage *createMinutesPackage(){ return new LargeMinutesPackage(); }
    ISMSPackage *createSMSPackage(){ return new LowSMSPackage(); }
};

class CheaperSmsAgreementFactory : public AgreementFactory
{
  public:
    IMinutesPackage *createMinutesPackage(){ return new LowMinutesPackage(); }
    ISMSPackage *createSMSPackage(){ return new LargeSMSPackage(); }
};


class Agreement
{
    AgreementFactory *agreementFactory;

  public:
    Agreement(AgreementFactory *agreementFactory){ this->agreementFactory = agreementFactory; }
    void GenerateAgreement()
    {
      IMinutesPackage *minutesPackage = this->agreementFactory->createMinutesPackage();
      ISMSPackage *smsPackage = this->agreementFactory->createSMSPackage();
    }
};

int main()
{
  Agreement *agreement1 = new Agreement(new EconomicAgreementFactory());
  agreement1->GenerateAgreement();
  Agreement *agreement2 = new Agreement(new GoldAgreementFactory());
  agreement2->GenerateAgreement();
  Agreement *agreement3 = new Agreement(new CheaperMinutesAgreementFactory());
  agreement3->GenerateAgreement();
  Agreement *agreement4 = new Agreement(new CheaperSmsAgreementFactory());
  agreement4->GenerateAgreement();

  return 0;
}
