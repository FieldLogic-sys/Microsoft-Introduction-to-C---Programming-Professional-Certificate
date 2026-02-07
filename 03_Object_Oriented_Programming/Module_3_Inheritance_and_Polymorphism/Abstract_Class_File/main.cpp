#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Primary Interface
// Per teaching "Any class that wants to 'process' data must follow this rule."

class IProcessorStage
{
public:
    // Remember the destructor to prevent leaks!!!
  
    virtual ~IProcessorStage() = default;

    virtual std::string process(const std::string &input) = 0;
};

// A secondary interface for converting data formats

class IDataConverter
{
public:
    virtual ~IDataConverter() = default;

    virtual std::string convert(const std::string &input) = 0;
};


class NormalizationStage : public IProcessorStage {
    public:
        std::string process(const std::string& input) override {
            return "Cleaned: " + input;
        }
};


// Puts text into tags


class HTMLConverter : public IDataConverter {
    public:
        std::string convert(const std::string& input) override {
            return "<p>" + input + "</p>";
        }
};


class SmartMarkdownHandler : public IProcessorStage, public IDataConverter {
    public:
    // Contract 1
        std::string process(const std::string& input) override {
            return "Processed: " + input;
        }


        // Contract 2
        std::string convert(const std::string& input) override {
            return "<html>" + input + "</html>";
        }
};



int main() {


// 1. The setup: a list that only knows about the Interface (Shelf like)
std::vector<std::shared_ptr<IProcessorStage>> pipeline;

// 2. The plug-in: Add different types of workers to the same list
pipeline.push_back(std::make_shared<NormalizationStage>());

// Proving Multiple Inheritance creating the 'Smart' worker and put it into the 'Processor' list
auto smartWorker = std::make_shared<SmartMarkdownHandler>();
pipeline.push_back(smartWorker);

// 3. The Polymorphic test and all are treated as the same type and call 'process'


std::cout << "--- Starting Polymorphic Test --- " << std::endl;
std::string testNote = "My Obsidian Note";

for (const auto& stage : pipeline) {
    // Don't know if 'stage' is Normalization or SmartMarkdown but do know it follows the IProcessorStage contract.
    std::cout << stage->process(testNote) << std::endl;
    }


    // 4. Multi-Role Test
    std::cout << "\n--- Testing Multi-Role Capability ---" << std::endl;
    std::cout << "As a Converter: " << smartWorker->convert(testNote) << std::endl;

    return 0;
};