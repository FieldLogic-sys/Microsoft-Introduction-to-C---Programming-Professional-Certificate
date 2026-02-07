#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Primary Interface
// Per teaching "Any class that wants to 'process' data must follow this rule."

// Grandparent

class IBase
{
public:
    virtual ~IBase() = default;
    virtual void printRole() = 0;
};
class IProcessorStage : virtual public IBase
{
public:
    virtual std::string process(const std::string &input) = 0;
};

// A secondary interface for converting data formats

class IDataConverter : virtual public IBase
{
public:
virtual ~IDataConverter() = default;
    virtual std::string convert(const std::string &input) = 0;
};

class NormalizationStage : public IProcessorStage
{
public:
    void printRole() override {std::cout << "Role: Normalizer" << std::endl;}
    std::string process(const std::string &input) override
    {
        return "Cleaned: " + input;
    }
};

// Puts text into tags

class HTMLConverter : public IDataConverter
{
public:
void printRole() override { std::cout << "Role: HTML Converter" << std::endl; }
    std::string convert(const std::string &input) override
    {
        return "<p>" + input + "</p>";
    }
};

class SmartMarkdownHandler : public IProcessorStage, public IDataConverter
{
public:
void printRole() override { std::cout << "Role: Smart Markdown"<<std::endl;}
    // Contract 1
    std::string process(const std::string &input) override
    {
        return "Processed: " + input;
    }

    // Contract 2
    std::string convert(const std::string &input) override
    {
        return "<html>" + input + "</html>";
    }
};

class SmartWorker : public IProcessorStage, public IDataConverter
{
public:
    void printRole() override
    {
        std::cout << "I am a SmartWorker: I can Process and Convert." << std::endl;
    }
    std::string process(const std::string &input) override
    {
        return "Processed: " + input;
    }

    // Fulfilling the Converter contract
    std::string convert(const std::string &input) override
    {
        return "<html>" + input + "</html>";
    }
};

int main()
{

    // 1. The setup: a list that only knows about the Interface (Shelf like)
    std::vector<std::shared_ptr<IProcessorStage>> pipeline;

    // 2. The plug-in: Add different types of workers to the same list
    pipeline.push_back(std::make_shared<NormalizationStage>());

   
    auto smartWorker = std::make_shared<SmartMarkdownHandler>();
    pipeline.push_back(smartWorker);

    // 3. The Polymorphic test and all are treated as the same type and call 'process'

    std::cout << "--- Starting Polymorphic Test --- " << std::endl;
    std::string currentNote = "My Obsidian Note";
    int count = 0;
    for (const auto &stage : pipeline)
    {
       
        stage->printRole();


        currentNote = stage->process(currentNote);
        count++;
       std::cout << "Data after stage: " << currentNote << "\n" << count << std::endl;

    }

    // 4. Multi-Role Test
 std::cout << "--- Final Output (HTML Conversion) ---" << std::endl;
    std::cout << smartWorker->convert(currentNote) << std::endl;

    // 5. SMARTWORKER DIAMOND TEST (Verification)
    std::cout << "\n--- Diamond Problem Verification ---" << std::endl;
    std::shared_ptr<SmartWorker> myTool = std::make_shared<SmartWorker>();
    myTool->printRole(); // Proves the shared grandparent works

    return 0;
};