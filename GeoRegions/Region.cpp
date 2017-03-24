//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;


Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
       // DONE: Add cases for State, County, and City
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
            default:
                break;
        }

        // If the region isn't valid, git ride of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
}

Region::~Region()
{
    // Done: cleanup any dynamically allocated objects
    if(m_elementsAllocated != 0)
    {
        for (int i = 0; i < m_countRegion; i++ )
        {
            delete m_region[i];
        }
        delete [] m_region;
    }
}

std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation(unsigned int pop) {
    // DONE: implement computeTotalPopulation, such that the result is m_population + the total population for all sub-regions
    unsigned int result = pop;
    for (int i = 0; i < m_countRegion; ++i) {
        result += m_region[i]->computeTotalPopulation(m_region[i]->m_population);
    }
    return result;
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << getName() << ":" << std::endl;

    // TODO: implement the loop in the list method foreach subregion, print out id name
    int i = 0;
    do {
        if(m_region[i] != nullptr && m_region[i]->m_isValid){
            m_region[i]->display(out, 0, false);
            i++;
        }
    }while (i < m_countRegion);
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation(0);
    double area = getArea();
    double density = (double) totalPopulation / area;

    // DONE: compute the totalPopulation using a method
    compute(totalPopulation);

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        // DONE: implement loop in display method
        // foreach subregion
        //      display that subregion at displayLevel+1 with the same showChild value
        int i = 0;
        do {
            if(m_region[i] != nullptr && m_region[i]->m_isValid){
                m_region[i]->display(out, displayLevel+1, showChild);
                i++;
            }
        }while (i < m_countRegion);
    }
}

void Region::save(std::ostream& out)
{
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    // DONE: implement loop in save method to save each sub-region
    // foreach subregion,
    //      save that region
    int i = 0;
    do {
        if(m_region[i] != nullptr && m_region[i]->m_isValid){
            m_region[i]->save(out);
            i++;
        }
    }while (i < m_countRegion);

    out << regionDelimiter << std::endl;
}

void Region::validate()
{
    m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
}

void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        line = trim(line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                // DONE: Add the new sub-region to this region
                this->addRegion(child);
                child->loadChildren(in);

            }
        }
    }
}

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}

void Region::increaseSize() {
    int i = 0;
    m_elementsAllocated *= 2;
    Region** tmpRegion = new Region*[m_elementsAllocated];
    do{
        tmpRegion[i] = m_region[i];
        i++;
    }while(i < m_elementsAllocated);

    delete [] m_region;
    m_region = tmpRegion;
    //clean up
    delete [] tmpRegion;
    tmpRegion = nullptr;
}
unsigned int Region::compute(unsigned int pop){
    int population = pop;
    if(m_region!= nullptr) {
        for (int i = 0; i < m_countRegion; i++) {
            population += m_region[i]->getPopulation();
            population = m_region[i]->compute(population);
        }
    }
    return population;
}

void Region::addRegion(Region* region){
    if(m_region== nullptr){
        m_region = new Region* [10];
    }
        if (region!= nullptr)
        {
            if (m_elementsAllocated == 0) {
                m_region = new Region *[10];
                m_elementsAllocated = 10;
            }

            if (m_countRegion == m_elementsAllocated)
                increaseSize();

            m_region[m_countRegion++] = region;
        }

}

Region *Region::getSubRegionByIndex(unsigned int index) {
    Region* result = nullptr;
    if(m_countRegion > 0 && index < m_countRegion){
        result = m_region[index];
    }
    return result;
}

Region *Region::lookUpSubRegionByIndex(unsigned int index) {
    Region* result = nullptr;
    for(int i = 0; i < m_countRegion; i++){
        if(m_region[i]->getId() == index){
            result = m_region[i];
        }
    }
    return result;
}

void Region::removeRegion(Region* region) {
    {
        int position = 0;

        if (region == nullptr) {
            printf("Region does not exist!\n");
        } else {
            for (int i = 0; i < m_countRegion; ++i) {
                if (m_region[i]->getId() == region->getId()) {
                    position = i;
                }
            }

            delete region;
            region = nullptr;

            for (int j = position; j < m_countRegion - 1; j++) {
                m_region[j] = m_region[j + 1];
            }
            m_countRegion--;
            printf("Deleted!\n");
        }
    }
}