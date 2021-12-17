#include <iostream>
#include <vector>

class Hopper
{
    private:
	int currentlyStoredBeans;
    	int maximumStoredBeans;

    public:
	Hopper()
    	{
        	currentlyStoredBeans = 0; 
        	maximumStoredBeans = 200;
    	}

	int UseBeans(int gramsOfBeans)
	{
		currentlyStoredBeans -= gramsOfBeans;
        	std::cout << "Barista: \"I'm using " << gramsOfBeans << " grams of beans on this cup!\"" << std::endl;
        	std::cout << "Barista: \"There are " << currentlyStoredBeans << " grams of beans left in the hopper!\"" << std::endl;
		return gramsOfBeans;
	}
	
	void AddBeans(int gramsOfBeans)
	{
		this->currentlyStoredBeans += gramsOfBeans;
        	std::cout << "Barista: \"I've added " << this->currentlyStoredBeans << " grams of beans into the hopper!\"" << std::endl;
        	if(currentlyStoredBeans == 200)
        	{
            		std::cout << "Barista: \"The hopper is full!\"" << std::endl;
        	}
	}
};

class WaterReservoir
{
    private:
	float currentWaterAmount;
    	float maximumWaterAmount;
	int waterTemperature;

    public:
	WaterReservoir()
    	{
        	currentWaterAmount = 0.0; 
        	maximumWaterAmount = 1.0; 
        	waterTemperature = 30;
    	}

    	void AddWater(const int liters)
	{
		currentWaterAmount += liters;
		std::cout << "Barista: \"I've added " << this->currentWaterAmount << " liters of water into the water reservoir!\"" << std::endl;
		if(currentWaterAmount == 1)
        	{
            		std::cout << "Barista: \"The water reservoir is full!\"" << std::endl;
        	}
	}
	
	void ChangeWaterTemperature(const int temperature)
	{
        	std::cout << "Barista: \"The water temperature is currently at " << waterTemperature << " degrees Celsius!\"" << std::endl;
		waterTemperature = temperature;
        	if (waterTemperature == 100)
        	{
            		std::cout << "Barista: \"The water is now at " << temperature << " degrees Celcius, which is max temperature!\"" << std::endl;
        	}
	}

	bool UseWater()
	{
        	std::cout << "Barista: \"I'm using .25 liters of hot water on this cup!\"" << std::endl;
        	currentWaterAmount -= .25;
        	std::cout << "Barista: \"There is " << currentWaterAmount << " liters of hot water left in the water reservoir!\"" << std::endl;
		return true;
	}
};

class HeatSource
{
    public:
	HeatSource()
    	{

    	}

	void HeatUpWater(WaterReservoir *waterReservoir)
	{
		std::cout << "Barista: \"I'm heating up the water now!\"" << std::endl;
        	waterReservoir->ChangeWaterTemperature(100);
	}
};

class Grinder
{
    public:
	Grinder()
    	{

    	}

	bool GrindBeans(Hopper *hopper)
	{
        	hopper->UseBeans(50);
		return true;
	}
};

class CupRecepticle
{
    public:
	CupRecepticle()
    	{

    	}
	
	bool FinishCoffee(Grinder *grinder, WaterReservoir *waterReservoir, Hopper *hopper)
	{
		if (grinder->GrindBeans(hopper) && waterReservoir->UseWater())
		{
			std::cout << "Barista: \"I'm finishing up this cup right now!\"" << std::endl;
			return true;
		}
	}
};

class Barista
{
    public:
	Hopper *hopper;
	WaterReservoir *waterReservoir;
	HeatSource *heatsource;
	Grinder *grinder;
	CupRecepticle *cuprecepticle;
	
	Barista()
	{
		hopper = new Hopper();
		waterReservoir = new WaterReservoir();
		heatsource = new HeatSource();
		grinder = new Grinder();
		cuprecepticle = new CupRecepticle();
	}

	bool AskHowManyCups()
	{
        	int cupsRequested;
        	std::cout << "Barista: \"How many cups of coffee would you like?\"" <<std::endl;
        	std::cin >> cupsRequested;

		if (cupsRequested <= 0 || cupsRequested > 4)
		{
			std::cout << "Barista: \"I can only make between 1 and 4 cups at a time!\"" << std::endl;
            		AskHowManyCups();
            		return false;
		}

		heatsource->HeatUpWater(waterReservoir);

		for (int i = 0; i < cupsRequested; i++)
		{
			if (cuprecepticle->FinishCoffee(grinder, waterReservoir, hopper))
			{
				std::cout << "Barista: \"That's " << i+1 << " cup(s) of coffee made!\"" << std::endl;
			}
		}
		std::cout << "Barista: \"Enjoy your coffee!\"" << std::endl;
		return true;
	}

	void FillHopper()
	{
		hopper->AddBeans(200);
	}

	void FillReservoir()
	{
		this->waterReservoir->AddWater(1.0);
	}
};

int main()
{
	Barista *Joey = new Barista();
    
	Joey->FillHopper();
	Joey->FillReservoir();
	Joey->AskHowManyCups();
}
