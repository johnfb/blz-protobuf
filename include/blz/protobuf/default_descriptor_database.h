
#pragma once
#include <google/protobuf/descriptor_database.h>
#include <blz/protobuf/config.h>
namespace blz
{
namespace protobuf
{

class DefaultDescriptorDatabase : public google::protobuf::DescriptorDatabase
{
public:
    DefaultDescriptorDatabase();
    virtual ~DefaultDescriptorDatabase();    
    virtual bool FindFileByName(const string& filename, FileDescriptorProto* output);
    virtual bool FindFileContainingSymbol(const string& symbol_name, FileDescriptorProto* output);
    virtual bool FindFileContainingExtension(const string& containing_type, int field_number, FileDescriptorProto* output);
    virtual bool FindAllExtensionNumbers(const string& extendee_type , vector<int>* output);
};

}
}
