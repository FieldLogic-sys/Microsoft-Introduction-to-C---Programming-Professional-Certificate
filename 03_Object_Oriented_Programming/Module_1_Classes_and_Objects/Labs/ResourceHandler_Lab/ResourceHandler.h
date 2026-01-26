/**
 * @file ResourceHandler.h
 * @brief Header file for the ResourceHandler class.
 * @details Implements RAII (Resource Acquisition Is Initialization) to manage 
 * industrial file streams safely.
 */

#ifndef RESOURCE_HANDLER_H
#define RESOURCE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>

/**
 * @class ResourceHandler
 * @brief Manages the lifecycle of a file resource.
 * @details Ensures that file handles are acquired upon construction and 
 * guaranteed to close upon destruction, preventing resource leaks.
 */
class ResourceHandler {
private:
    std::string filePath;   /**< The destination path for the resource. */
    std::fstream fileStream; /**< The active file stream handle. */

public:
    /**
     * @brief Default Constructor.
     * @details Initializes a handler in a dormant state without binding to a file.
     */
    ResourceHandler();

    /**
     * @brief Parameterized Constructor.
     * @param path The system path to the file resource.
     * @details Immediately attempts to acquire the file handle (RAII Acquisition).
     */
    ResourceHandler(const std::string& path);

    /**
     * @brief Copy Constructor (Deep Copy).
     * @param other The existing ResourceHandler to clone.
     * @details Creates a new file connection to prevent "Hanging References."
     */
    ResourceHandler(const ResourceHandler& other);

    /**
     * @brief Destructor.
     * @details Automatically releases the file handle (RAII Release).
     */
    ~ResourceHandler();

    /**
     * @brief Writes telemetry data to the resource.
     * @param text The string data to be persisted.
     */
    void write(const std::string& text);
};

#endif