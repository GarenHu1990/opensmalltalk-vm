/* Automatically generated by
	VMPluginCodeGenerator * VMMaker.oscog-eem.84 uuid: 65d3d0e0-a9bb-4d56-ad24-df44e8dc0e37
   from
	FilePlugin * VMMaker.oscog-eem.84 uuid: 65d3d0e0-a9bb-4d56-ad24-df44e8dc0e37
 */
static char __buildInfo[] = "FilePlugin * VMMaker.oscog-eem.84 uuid: 65d3d0e0-a9bb-4d56-ad24-df44e8dc0e37 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "FilePlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/
#define COGMTVM 0
#define DirBadPath 2
#define DirNoMoreEntries 1
#define PrimErrBadArgument 3
#define PrimErrBadIndex 4
#define PrimErrNoMemory 9
#define PrimErrObjectMayMove 14
#define PrimErrUnsupported 7
#define PrimNoErr 0


/*** Function Prototypes ***/
static sqInt asciiDirectoryDelimiter(void);
EXPORT(sqInt) fileOpenNamesizewritesecure(char *nameIndex, sqInt nameSize, sqInt writeFlag, sqInt secureFlag);
sqInt fileRecordSize(void);
SQFile * fileValueOf(sqInt objectPointer);
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) getThisSession(void);
static sqInt halt(void);
EXPORT(sqInt) initialiseModule(void);
static sqInt makeDirEntryNamesizecreateDatemodDateisDirfileSize(char *entryName, sqInt entryNameSize, sqInt createDate, sqInt modifiedDate, sqInt dirFlag, squeakFileOffsetType  fileSize);
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveDirectoryCreate(void);
EXPORT(sqInt) primitiveDirectoryDelete(void);
EXPORT(sqInt) primitiveDirectoryDelimitor(void);
EXPORT(sqInt) primitiveDirectoryEntry(void);
EXPORT(sqInt) primitiveDirectoryGetMacTypeAndCreator(void);
EXPORT(sqInt) primitiveDirectoryLookup(void);
EXPORT(sqInt) primitiveDirectorySetMacTypeAndCreator(void);
EXPORT(sqInt) primitiveDisableFileAccess(void);
EXPORT(sqInt) primitiveFileAtEnd(void);
EXPORT(sqInt) primitiveFileClose(void);
EXPORT(sqInt) primitiveFileDelete(void);
EXPORT(sqInt) primitiveFileFlush(void);
EXPORT(sqInt) primitiveFileGetPosition(void);
EXPORT(sqInt) primitiveFileOpen(void);
EXPORT(sqInt) primitiveFileRead(void);
EXPORT(sqInt) primitiveFileRename(void);
EXPORT(sqInt) primitiveFileSetPosition(void);
EXPORT(sqInt) primitiveFileSize(void);
EXPORT(sqInt) primitiveFileStdioHandles(void);
EXPORT(sqInt) primitiveFileTruncate(void);
EXPORT(sqInt) primitiveFileWrite(void);
EXPORT(sqInt) primitiveHasFileAccess(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) setMacFileTypeAndCreator(char *fileName, char *typeString, char *creatorString);
EXPORT(sqInt) shutdownModule(void);


/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FilePlugin * VMMaker.oscog-eem.84 (i)"
#else
	"FilePlugin * VMMaker.oscog-eem.84 (e)"
#endif
;
static void * sCCPfn;
static void * sCDFfn;
static void * sCDPfn;
static void * sCGFTfn;
static void * sCLPfn;
static void * sCOFfn;
static void * sCRFfn;
static void * sCSFTfn;
static void * sDFAfn;
static void * sHFAfn;


static sqInt
asciiDirectoryDelimiter(void)
{
	return dir_Delimitor();
}


/*	Open the named file, possibly checking security. Answer the file oop. */

EXPORT(sqInt)
fileOpenNamesizewritesecure(char *nameIndex, sqInt nameSize, sqInt writeFlag, sqInt secureFlag)
{
    SQFile *file;
    sqInt fileOop;
    sqInt okToOpen;

	fileOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(SQFile));
	/* begin fileValueOf: */
	if (!((interpreterProxy->isBytes(fileOop))
		 && ((interpreterProxy->byteSizeOf(fileOop)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(fileOop);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		if (secureFlag) {
			if (sCOFfn != 0) {
				okToOpen = ((sqInt (*) (char *, sqInt, sqInt)) sCOFfn)(nameIndex, nameSize, writeFlag);
				if (!(okToOpen)) {
					interpreterProxy->primitiveFail();
				}
			}
		}
	}
	if (!(interpreterProxy->failed())) {
		sqFileOpen(file, nameIndex, nameSize, writeFlag);
	}
	return fileOop;
}


/*	Return the size of a Smalltalk file record in bytes. */

sqInt
fileRecordSize(void)
{
	return sizeof(SQFile);
}


/*	Return a pointer to the first byte of of the file record within the given
	Smalltalk object, or nil if objectPointer is not a file record.
 */

SQFile *
fileValueOf(sqInt objectPointer)
{
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	return interpreterProxy->firstIndexableField(objectPointer);
}


/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}


/*	Exported entry point for the VM. Only used by AsynchFilePlugin and needs
	to be reowrked now we have a VM global session Id capability
 */

EXPORT(sqInt)
getThisSession(void)
{
	return sqFileThisSession();
}

static sqInt
halt(void)
{
	;
	return 0;
}

EXPORT(sqInt)
initialiseModule(void)
{
	sCCPfn = interpreterProxy->ioLoadFunctionFrom("secCanCreatePathOfSize", "SecurityPlugin");
	sCDPfn = interpreterProxy->ioLoadFunctionFrom("secCanDeletePathOfSize", "SecurityPlugin");
	sCGFTfn = interpreterProxy->ioLoadFunctionFrom("secCanGetFileTypeOfSize", "SecurityPlugin");
	sCLPfn = interpreterProxy->ioLoadFunctionFrom("secCanListPathOfSize", "SecurityPlugin");
	sCSFTfn = interpreterProxy->ioLoadFunctionFrom("secCanSetFileTypeOfSize", "SecurityPlugin");
	sDFAfn = interpreterProxy->ioLoadFunctionFrom("secDisableFileAccess", "SecurityPlugin");
	sCDFfn = interpreterProxy->ioLoadFunctionFrom("secCanDeleteFileOfSize", "SecurityPlugin");
	sCOFfn = interpreterProxy->ioLoadFunctionFrom("secCanOpenFileOfSizeWritable", "SecurityPlugin");
	sCRFfn = interpreterProxy->ioLoadFunctionFrom("secCanRenameFileOfSize", "SecurityPlugin");
	sHFAfn = interpreterProxy->ioLoadFunctionFrom("secHasFileAccess", "SecurityPlugin");
	return sqFileInit();
}

static sqInt
makeDirEntryNamesizecreateDatemodDateisDirfileSize(char *entryName, sqInt entryNameSize, sqInt createDate, sqInt modifiedDate, sqInt dirFlag, squeakFileOffsetType  fileSize)
{
    sqInt createDateOop;
    sqInt fileSizeOop;
    sqInt i;
    sqInt modDateOop;
    sqInt nameString;
    sqInt results;
    char *stringPtr;

	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 5));
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), entryNameSize));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(createDate));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive32BitIntegerFor(modifiedDate));
	interpreterProxy->pushRemappableOop(interpreterProxy->positive64BitIntegerFor(fileSize));
	fileSizeOop = interpreterProxy->popRemappableOop();
	modDateOop = interpreterProxy->popRemappableOop();
	createDateOop = interpreterProxy->popRemappableOop();
	nameString = interpreterProxy->popRemappableOop();

	/* copy name into Smalltalk string */

	results = interpreterProxy->popRemappableOop();
	stringPtr = interpreterProxy->firstIndexableField(nameString);
	for (i = 0; i <= (entryNameSize - 1); i += 1) {
		stringPtr[i] = (entryName[i]);
	}
	interpreterProxy->storePointerofObjectwithValue(0, results, nameString);
	interpreterProxy->storePointerofObjectwithValue(1, results, createDateOop);
	interpreterProxy->storePointerofObjectwithValue(2, results, modDateOop);
	if (dirFlag) {
		interpreterProxy->storePointerofObjectwithValue(3, results, interpreterProxy->trueObject());
	}
	else {
		interpreterProxy->storePointerofObjectwithValue(3, results, interpreterProxy->falseObject());
	}
	interpreterProxy->storePointerofObjectwithValue(4, results, fileSizeOop);
	return results;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(sqInt)
moduleUnloaded(char *aModuleName)
{
	if ((strcmp(aModuleName, "SecurityPlugin")) == 0) {
		sCCPfn = sCDPfn = sCGFTfn = sCLPfn = sCSFTfn = sDFAfn = sCDFfn = sCOFfn = sCRFfn = sHFAfn = 0;
	}
}

static sqInt
msg(char *s)
{
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(sqInt)
primitiveDirectoryCreate(void)
{
    sqInt dirName;
    char *dirNameIndex;
    sqInt dirNameSize;
    sqInt okToCreate;

	dirName = interpreterProxy->stackValue(0);
	if (!(interpreterProxy->isBytes(dirName))) {
		return interpreterProxy->primitiveFail();
	}
	dirNameIndex = interpreterProxy->firstIndexableField(dirName);

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	dirNameSize = interpreterProxy->byteSizeOf(dirName);
	if (sCCPfn != 0) {
		okToCreate =  ((sqInt (*)(char *, sqInt))sCCPfn)(dirNameIndex, dirNameSize);
		if (!(okToCreate)) {
			return interpreterProxy->primitiveFail();
		}
	}
	if (!(dir_Create(dirNameIndex, dirNameSize))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
}

EXPORT(sqInt)
primitiveDirectoryDelete(void)
{
    sqInt dirName;
    char *dirNameIndex;
    sqInt dirNameSize;
    sqInt okToDelete;

	dirName = interpreterProxy->stackValue(0);
	if (!(interpreterProxy->isBytes(dirName))) {
		return interpreterProxy->primitiveFail();
	}
	dirNameIndex = interpreterProxy->firstIndexableField(dirName);

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	dirNameSize = interpreterProxy->byteSizeOf(dirName);
	if (sCDPfn != 0) {
		okToDelete =  ((sqInt (*)(char *, sqInt))sCDPfn)(dirNameIndex, dirNameSize);
		if (!(okToDelete)) {
			return interpreterProxy->primitiveFail();
		}
	}
	if (!(dir_Delete(dirNameIndex, dirNameSize))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(1);
}

EXPORT(sqInt)
primitiveDirectoryDelimitor(void)
{
    sqInt ascii;

	ascii = asciiDirectoryDelimiter();
	if (!((ascii >= 0)
		 && (ascii <= 255))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->popthenPush(1, interpreterProxy->fetchPointerofObject(ascii, interpreterProxy->characterTable()));
}


/*	Two arguments - directory path, and simple file name;
	returns an array (see primitiveDirectoryLookup) describing the file or
	directory, or nil if it does not exist. 
	Primitive fails if the outer path does not identify a readable directory.
	(This is a lookup-by-name variant of primitiveDirectoryLookup.) */

EXPORT(sqInt)
primitiveDirectoryEntry(void)
{
    sqInt createDate;
    sqInt dirFlag;
    char entryName[256];
    sqInt entryNameSize;
    squeakFileOffsetType fileSize;
    sqInt modifiedDate;
    sqInt okToList;
    sqInt pathName;
    char *pathNameIndex;
    sqInt pathNameSize;
    char *reqNameIndex;
    sqInt reqNameSize;
    sqInt requestedName;
    sqInt status;

	requestedName = interpreterProxy->stackValue(0);
	pathName = interpreterProxy->stackValue(1);
	if (!(interpreterProxy->isBytes(pathName))) {
		return interpreterProxy->primitiveFail();
	}
	pathNameIndex = interpreterProxy->firstIndexableField(pathName);
	pathNameSize = interpreterProxy->byteSizeOf(pathName);
	reqNameIndex = interpreterProxy->firstIndexableField(requestedName);

	/* If the security plugin can be loaded, use it to check for permission. 
	If not, assume it's ok */

	reqNameSize = interpreterProxy->byteSizeOf(requestedName);
	if (sCLPfn != 0) {
		okToList = ((sqInt (*)(char *, sqInt))sCLPfn)(pathNameIndex, pathNameSize);
	}
	else {
		okToList = 1;
	}
	if (okToList) {
		status = dir_EntryLookup(pathNameIndex, pathNameSize, reqNameIndex, reqNameSize,
													  entryName, &entryNameSize, &createDate,
													  &modifiedDate, &dirFlag, &fileSize);
	}
	else {
		status = DirNoMoreEntries;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	if (status == DirNoMoreEntries) {
		interpreterProxy->popthenPush(3, interpreterProxy->nilObject());
		return null;
	}
	if (status == DirBadPath) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->popthenPush(3, makeDirEntryNamesizecreateDatemodDateisDirfileSize(entryName, entryNameSize, createDate, modifiedDate, dirFlag, fileSize));
}

EXPORT(sqInt)
primitiveDirectoryGetMacTypeAndCreator(void)
{
    sqInt creatorString;
    char *creatorStringIndex;
    sqInt fileName;
    char *fileNameIndex;
    sqInt fileNameSize;
    sqInt okToGet;
    sqInt typeString;
    char *typeStringIndex;

	creatorString = interpreterProxy->stackValue(0);
	typeString = interpreterProxy->stackValue(1);
	fileName = interpreterProxy->stackValue(2);
	if (!((interpreterProxy->isBytes(creatorString))
		 && ((interpreterProxy->byteSizeOf(creatorString)) == 4))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->isBytes(typeString))
		 && ((interpreterProxy->byteSizeOf(typeString)) == 4))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isBytes(fileName))) {
		return interpreterProxy->primitiveFail();
	}
	creatorStringIndex = interpreterProxy->firstIndexableField(creatorString);
	typeStringIndex = interpreterProxy->firstIndexableField(typeString);
	fileNameIndex = interpreterProxy->firstIndexableField(fileName);

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	fileNameSize = interpreterProxy->byteSizeOf(fileName);
	if (sCGFTfn != 0) {
		okToGet =  ((sqInt (*)(char *, sqInt))sCGFTfn)(fileNameIndex, fileNameSize);
		if (!(okToGet)) {
			return interpreterProxy->primitiveFail();
		}
	}
	if (!(dir_GetMacFileTypeAndCreator(fileNameIndex, fileNameSize, typeStringIndex, creatorStringIndex))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(3);
}

EXPORT(sqInt)
primitiveDirectoryLookup(void)
{
    sqInt createDate;
    sqInt dirFlag;
    char entryName[256];
    sqInt entryNameSize;
    squeakFileOffsetType fileSize;
    sqInt index;
    sqInt modifiedDate;
    sqInt okToList;
    sqInt pathName;
    char *pathNameIndex;
    sqInt pathNameSize;
    sqInt status;

	index = interpreterProxy->stackIntegerValue(0);
	pathName = interpreterProxy->stackValue(1);
	if (!(interpreterProxy->isBytes(pathName))) {
		return interpreterProxy->primitiveFail();
	}
	pathNameIndex = interpreterProxy->firstIndexableField(pathName);

	/* If the security plugin can be loaded, use it to check for permission. 
	If not, assume it's ok */

	pathNameSize = interpreterProxy->byteSizeOf(pathName);
	if (sCLPfn != 0) {
		okToList = ((sqInt (*)(char *, sqInt))sCLPfn)(pathNameIndex, pathNameSize);
	}
	else {
		okToList = 1;
	}
	if (okToList) {
		status = dir_Lookup(pathNameIndex, pathNameSize, index,
												entryName, &entryNameSize, &createDate,
												&modifiedDate, &dirFlag, &fileSize);
	}
	else {
		status = DirNoMoreEntries;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	if (status == DirNoMoreEntries) {
		interpreterProxy->popthenPush(3, interpreterProxy->nilObject());
		return null;
	}
	if (status == DirBadPath) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->popthenPush(3, makeDirEntryNamesizecreateDatemodDateisDirfileSize(entryName, entryNameSize, createDate, modifiedDate, dirFlag, fileSize));
}

EXPORT(sqInt)
primitiveDirectorySetMacTypeAndCreator(void)
{
    sqInt creatorString;
    char *creatorStringIndex;
    sqInt fileName;
    char *fileNameIndex;
    sqInt fileNameSize;
    sqInt okToSet;
    sqInt typeString;
    char *typeStringIndex;

	creatorString = interpreterProxy->stackValue(0);
	typeString = interpreterProxy->stackValue(1);
	fileName = interpreterProxy->stackValue(2);
	if (!((interpreterProxy->isBytes(creatorString))
		 && ((interpreterProxy->byteSizeOf(creatorString)) == 4))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->isBytes(typeString))
		 && ((interpreterProxy->byteSizeOf(typeString)) == 4))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->isBytes(fileName))) {
		return interpreterProxy->primitiveFail();
	}
	creatorStringIndex = interpreterProxy->firstIndexableField(creatorString);
	typeStringIndex = interpreterProxy->firstIndexableField(typeString);
	fileNameIndex = interpreterProxy->firstIndexableField(fileName);

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	fileNameSize = interpreterProxy->byteSizeOf(fileName);
	if (sCSFTfn != 0) {
		okToSet =  ((sqInt (*)(char *, sqInt))sCSFTfn)(fileNameIndex, fileNameSize);
		if (!(okToSet)) {
			return interpreterProxy->primitiveFail();
		}
	}
	if (!(dir_SetMacFileTypeAndCreator(fileNameIndex, fileNameSize,typeStringIndex, creatorStringIndex))) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop(3);
}


/*	If the security plugin can be loaded, use it to turn off file access
	If not, assume it's ok */

EXPORT(sqInt)
primitiveDisableFileAccess(void)
{
	if (sDFAfn != 0) {
		((sqInt (*)(void))sDFAfn)();
	}
}

EXPORT(sqInt)
primitiveFileAtEnd(void)
{
    sqInt atEnd;
    SQFile *file;
    sqInt objectPointer;

	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(0);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		atEnd = sqFileAtEnd(file);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(2);
		interpreterProxy->pushBool(atEnd);
	}
}

EXPORT(sqInt)
primitiveFileClose(void)
{
    SQFile *file;
    sqInt objectPointer;

	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(0);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		sqFileClose(file);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt)
primitiveFileDelete(void)
{
    char *nameIndex;
    sqInt namePointer;
    sqInt nameSize;
    sqInt okToDelete;

	namePointer = interpreterProxy->stackValue(0);
	if (!(interpreterProxy->isBytes(namePointer))) {
		return interpreterProxy->primitiveFail();
	}
	nameIndex = interpreterProxy->firstIndexableField(namePointer);

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	nameSize = interpreterProxy->byteSizeOf(namePointer);
	if (sCDFfn != 0) {
		okToDelete =  ((sqInt (*)(char *, sqInt))sCDFfn)(nameIndex, nameSize);
		if (!(okToDelete)) {
			return interpreterProxy->primitiveFail();
		}
	}
	sqFileDeleteNameSize(nameIndex, nameSize);
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt)
primitiveFileFlush(void)
{
    SQFile *file;
    sqInt objectPointer;

	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(0);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		sqFileFlush(file);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(1);
	}
}

EXPORT(sqInt)
primitiveFileGetPosition(void)
{
    SQFile *file;
    sqInt objectPointer;
    squeakFileOffsetType position;

	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(0);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		position = sqFileGetPosition(file);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->popthenPush(2, interpreterProxy->positive64BitIntegerFor(position));
	}
}

EXPORT(sqInt)
primitiveFileOpen(void)
{
    sqInt filePointer;
    char *nameIndex;
    sqInt namePointer;
    sqInt nameSize;
    sqInt writeFlag;

	writeFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	namePointer = interpreterProxy->stackValue(1);
	if (!(interpreterProxy->isBytes(namePointer))) {
		return interpreterProxy->primitiveFail();
	}
	nameIndex = interpreterProxy->firstIndexableField(namePointer);
	nameSize = interpreterProxy->byteSizeOf(namePointer);
	filePointer = fileOpenNamesizewritesecure(nameIndex, nameSize, writeFlag, 1);
	if (!(interpreterProxy->failed())) {
		interpreterProxy->popthenPush(3, filePointer);
	}
}

EXPORT(sqInt)
primitiveFileRead(void)
{
    sqInt array;
    sqInt bytesRead;
    size_t count;
    size_t elementSize;
    SQFile *file;
    sqInt objectPointer;
    sqInt retryCount;
    size_t startIndex;

	retryCount = 0;
	count = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	startIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(1));
	while (1) {
		array = interpreterProxy->stackValue(2);
		/* begin fileValueOf: */
		objectPointer = interpreterProxy->stackValue(3);
		if (!((interpreterProxy->isBytes(objectPointer))
			 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
			interpreterProxy->primitiveFail();
			file = null;
			goto l1;
		}
		file = interpreterProxy->firstIndexableField(objectPointer);
	l1:	/* end fileValueOf: */;
		if ((interpreterProxy->failed())
		 || (!(interpreterProxy->isWordsOrBytes(array)))) {
			return interpreterProxy->primitiveFailFor(PrimErrBadArgument);
		}
		elementSize = (interpreterProxy->isWords(array)
			? 4
			: 1);
		if (!((startIndex >= 1)
			 && (((startIndex + count) - 1) <= (interpreterProxy->slotSizeOf(array))))) {
			return interpreterProxy->primitiveFailFor(PrimErrBadIndex);
		}
		bytesRead = sqFileReadIntoAt(file, count * elementSize, ((char *) (interpreterProxy->firstIndexableField(array))), (startIndex - 1) * elementSize);
		if (!(((interpreterProxy->primitiveFailureCode()) == PrimErrObjectMayMove)
 && (((retryCount += 1)) <= 2))) break;
		interpreterProxy->tenuringIncrementalGC();
		interpreterProxy->primitiveFailFor(PrimNoErr);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->popthenPush(5, (((bytesRead / elementSize) << 1) | 1));
	}
}

EXPORT(sqInt)
primitiveFileRename(void)
{
    char *newNameIndex;
    sqInt newNamePointer;
    sqInt newNameSize;
    sqInt okToRename;
    char *oldNameIndex;
    sqInt oldNamePointer;
    sqInt oldNameSize;

	newNamePointer = interpreterProxy->stackValue(0);
	oldNamePointer = interpreterProxy->stackValue(1);
	if (!((interpreterProxy->isBytes(newNamePointer))
		 && (interpreterProxy->isBytes(oldNamePointer)))) {
		return interpreterProxy->primitiveFail();
	}
	newNameIndex = interpreterProxy->firstIndexableField(newNamePointer);
	newNameSize = interpreterProxy->byteSizeOf(newNamePointer);
	oldNameIndex = interpreterProxy->firstIndexableField(oldNamePointer);

	/* If the security plugin can be loaded, use it to check for rename permission.
	If not, assume it's ok */

	oldNameSize = interpreterProxy->byteSizeOf(oldNamePointer);
	if (sCRFfn != 0) {
		okToRename =  ((sqInt (*)(char *, sqInt))sCRFfn)(oldNameIndex, oldNameSize);
		if (!(okToRename)) {
			return interpreterProxy->primitiveFail();
		}
	}
	sqFileRenameOldSizeNewSize(oldNameIndex, oldNameSize, newNameIndex, newNameSize);
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(2);
	}
}

EXPORT(sqInt)
primitiveFileSetPosition(void)
{
    SQFile *file;
    squeakFileOffsetType newPosition;
    sqInt objectPointer;
    sqInt sz;

	if (!(((interpreterProxy->stackValue(0)) & 1))) {
		sz = sizeof(squeakFileOffsetType);
		if ((interpreterProxy->byteSizeOf(interpreterProxy->stackValue(0))) > sz) {
			return interpreterProxy->primitiveFail();
		}
	}
	newPosition = interpreterProxy->positive64BitValueOf(interpreterProxy->stackValue(0));
	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(1);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		sqFileSetPosition(file, newPosition);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(2);
	}
}

EXPORT(sqInt)
primitiveFileSize(void)
{
    SQFile *file;
    sqInt objectPointer;
    squeakFileOffsetType size;

	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(0);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		size = sqFileSize(file);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->popthenPush(2, interpreterProxy->positive64BitIntegerFor(size));
	}
}


/*	Answer an Array of file handles for standard in, standard out and standard
	error, with nil in entries that are unvailable, e.g. because the platform
	does not provide
	standard error, etc. Fail if there are no standard i/o facilities on the
	platform or
	if the security plugin denies access or if memory runs out. */

EXPORT(sqInt)
primitiveFileStdioHandles(void)
{
    SQFile fileRecords[3];
    sqInt index;
    sqInt result;
    sqInt validMask;

	if (sHFAfn != 0) {
		if (!( ((sqInt (*)(void))sHFAfn)())) {
			return interpreterProxy->primitiveFailFor(PrimErrUnsupported);
		}
	}
	;
	validMask = sqFileStdioHandlesInto((&fileRecords));
	if (validMask == 0) {
		return interpreterProxy->primitiveFailFor(PrimErrUnsupported);
	}
	result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 3);
	if (result == null) {
		return interpreterProxy->primitiveFailFor(PrimErrNoMemory);
	}
	interpreterProxy->pushRemappableOop(result);
	for (index = 0; index <= 2; index += 1) {
		if ((validMask & (1 << index)) != 0) {
			result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), sizeof(SQFile));
			if (result == null) {
				interpreterProxy->popRemappableOop();
				return interpreterProxy->primitiveFailFor(PrimErrNoMemory);
			}
			interpreterProxy->storePointerofObjectwithValue(index, interpreterProxy->topRemappableOop(), result);
			memcpy(interpreterProxy->firstIndexableField(result), (&(fileRecords[index])), sizeof(SQFile));
		}
	}
	
#  if COGMTVM
	interpreterProxy->fullGC();

#  endif /* COGMTVM */

	result = interpreterProxy->popRemappableOop();
	interpreterProxy->popthenPush(1, result);
}


/*	ftruncate is not an ansi function so we have a macro to point to a
	suitable platform implementation
 */

EXPORT(sqInt)
primitiveFileTruncate(void)
{
    SQFile *file;
    sqInt objectPointer;
    sqInt sz;
    squeakFileOffsetType truncatePosition;

	if (!(((interpreterProxy->stackValue(0)) & 1))) {
		sz = sizeof(squeakFileOffsetType);
		if ((interpreterProxy->byteSizeOf(interpreterProxy->stackValue(0))) > sz) {
			return interpreterProxy->primitiveFail();
		}
	}
	truncatePosition = interpreterProxy->positive64BitValueOf(interpreterProxy->stackValue(0));
	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(1);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->failed())) {
		sqFileTruncate(file, truncatePosition);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(2);
	}
}

EXPORT(sqInt)
primitiveFileWrite(void)
{
    sqInt array;
    char *arrayIndex;
    size_t byteSize;
    sqInt bytesWritten;
    size_t count;
    SQFile *file;
    sqInt objectPointer;
    size_t startIndex;

	count = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(0));
	startIndex = interpreterProxy->positive32BitValueOf(interpreterProxy->stackValue(1));
	array = interpreterProxy->stackValue(2);
	/* begin fileValueOf: */
	objectPointer = interpreterProxy->stackValue(3);
	if (!((interpreterProxy->isBytes(objectPointer))
		 && ((interpreterProxy->byteSizeOf(objectPointer)) == (sizeof(SQFile))))) {
		interpreterProxy->primitiveFail();
		file = null;
		goto l1;
	}
	file = interpreterProxy->firstIndexableField(objectPointer);
l1:	/* end fileValueOf: */;
	if (!(interpreterProxy->isWordsOrBytes(array))) {
		return interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->isWords(array)) {
		byteSize = 4;
	}
	else {
		byteSize = 1;
	}
	if (!((startIndex >= 1)
		 && (((startIndex + count) - 1) <= (interpreterProxy->slotSizeOf(array))))) {
		return interpreterProxy->primitiveFail();
	}
	if (!(interpreterProxy->failed())) {

		/* Note: adjust startIndex for zero-origin indexing */

		arrayIndex = interpreterProxy->firstIndexableField(array);
		bytesWritten = sqFileWriteFromAt(file, count * byteSize, arrayIndex, (startIndex - 1) * byteSize);
	}
	if (!(interpreterProxy->failed())) {
		interpreterProxy->popthenPush(5, (((bytesWritten / byteSize) << 1) | 1));
	}
}

EXPORT(sqInt)
primitiveHasFileAccess(void)
{
    sqInt hasAccess;

	if (sHFAfn != 0) {
		hasAccess =  ((sqInt (*)(void))sHFAfn)();
	}
	else {
		hasAccess = 1;
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(hasAccess);
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


/*	Exported entry point for the VM. Needed for image saving only and no-op on
	anything but Macs.
 */

EXPORT(sqInt)
setMacFileTypeAndCreator(char *fileName, char *typeString, char *creatorString)
{
	return dir_SetMacFileTypeAndCreator(fileName, strlen(fileName), typeString, creatorString);
}

EXPORT(sqInt)
shutdownModule(void)
{
	return sqFileShutdown();
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* FilePlugin_exports[][3] = {
	{"FilePlugin", "fileOpenNamesizewritesecure", (void*)fileOpenNamesizewritesecure},
	{"FilePlugin", "getModuleName", (void*)getModuleName},
	{"FilePlugin", "getThisSession", (void*)getThisSession},
	{"FilePlugin", "initialiseModule", (void*)initialiseModule},
	{"FilePlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"FilePlugin", "primitiveDirectoryCreate", (void*)primitiveDirectoryCreate},
	{"FilePlugin", "primitiveDirectoryDelete", (void*)primitiveDirectoryDelete},
	{"FilePlugin", "primitiveDirectoryDelimitor", (void*)primitiveDirectoryDelimitor},
	{"FilePlugin", "primitiveDirectoryEntry", (void*)primitiveDirectoryEntry},
	{"FilePlugin", "primitiveDirectoryGetMacTypeAndCreator", (void*)primitiveDirectoryGetMacTypeAndCreator},
	{"FilePlugin", "primitiveDirectoryLookup", (void*)primitiveDirectoryLookup},
	{"FilePlugin", "primitiveDirectorySetMacTypeAndCreator", (void*)primitiveDirectorySetMacTypeAndCreator},
	{"FilePlugin", "primitiveDisableFileAccess", (void*)primitiveDisableFileAccess},
	{"FilePlugin", "primitiveFileAtEnd", (void*)primitiveFileAtEnd},
	{"FilePlugin", "primitiveFileClose", (void*)primitiveFileClose},
	{"FilePlugin", "primitiveFileDelete", (void*)primitiveFileDelete},
	{"FilePlugin", "primitiveFileFlush", (void*)primitiveFileFlush},
	{"FilePlugin", "primitiveFileGetPosition", (void*)primitiveFileGetPosition},
	{"FilePlugin", "primitiveFileOpen", (void*)primitiveFileOpen},
	{"FilePlugin", "primitiveFileRead", (void*)primitiveFileRead},
	{"FilePlugin", "primitiveFileRename", (void*)primitiveFileRename},
	{"FilePlugin", "primitiveFileSetPosition", (void*)primitiveFileSetPosition},
	{"FilePlugin", "primitiveFileSize", (void*)primitiveFileSize},
	{"FilePlugin", "primitiveFileStdioHandles", (void*)primitiveFileStdioHandles},
	{"FilePlugin", "primitiveFileTruncate", (void*)primitiveFileTruncate},
	{"FilePlugin", "primitiveFileWrite", (void*)primitiveFileWrite},
	{"FilePlugin", "primitiveHasFileAccess", (void*)primitiveHasFileAccess},
	{"FilePlugin", "setInterpreter", (void*)setInterpreter},
	{"FilePlugin", "setMacFileTypeAndCreator", (void*)setMacFileTypeAndCreator},
	{"FilePlugin", "shutdownModule", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#endif /* ifdef SQ_BUILTIN_PLUGIN */
