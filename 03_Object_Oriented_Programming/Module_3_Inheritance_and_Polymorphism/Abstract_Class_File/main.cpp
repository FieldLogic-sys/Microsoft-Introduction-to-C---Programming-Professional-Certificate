#include <string>

// Primary Interface
// Per teaching "Any class that wants to 'process' data must follow this rule."

class IProcessorStage
{
public:
    // Remember the destructor to prevent leaks!!!
    // TODO: why use Default instead of 0 here
    // Create abstract classes with pure virtual functions that capture essential responsibilities for your chosen scenario. Make sure these interfaces are clear and encapsulate the critical roles they must perform.

    // Data Persistence Layer Example: Define interfaces for IDataReader and IDataWriter.

    // Communication Protocol Example: Define IMessageReceiver and IMessageSender.

    // Processing Pipeline Example: Consider IProcessorStage and IDataConverter.

    // 💡 Tip: Ensure your interfaces encapsulate only the necessary actions to maintain a focused and clean separation of concerns.

    // ❗ Common Mistakes
    // Filling interfaces with implementation details.

    // Overloading interfaces, making them do too much.
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