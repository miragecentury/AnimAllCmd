#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1617827895/AnimallObjectBalance.o \
	${OBJECTDIR}/_ext/1617827895/AnimallObjectBridge.o \
	${OBJECTDIR}/_ext/1617827895/AnimallObjectGamelle.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolApiBalance.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolApiGamelle.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolCmd.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolQeoBalance.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolQeoBridge.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolQeoGamelle.o \
	${OBJECTDIR}/_ext/1617827895/AnimallToolQeoLogger.o \
	${OBJECTDIR}/_ext/1617827895/QeoAnimalEventMessage.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/senderanimallcmd

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/senderanimallcmd: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/senderanimallcmd ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1617827895/AnimallObjectBalance.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallObjectBalance.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallObjectBalance.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallObjectBalance.cpp

${OBJECTDIR}/_ext/1617827895/AnimallObjectBridge.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallObjectBridge.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallObjectBridge.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallObjectBridge.cpp

${OBJECTDIR}/_ext/1617827895/AnimallObjectGamelle.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallObjectGamelle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallObjectGamelle.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallObjectGamelle.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolApiBalance.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolApiBalance.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolApiBalance.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolApiBalance.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolApiGamelle.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolApiGamelle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolApiGamelle.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolApiGamelle.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolCmd.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolCmd.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolCmd.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolCmd.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolQeoBalance.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoBalance.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolQeoBalance.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoBalance.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolQeoBridge.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoBridge.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolQeoBridge.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoBridge.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolQeoGamelle.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoGamelle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolQeoGamelle.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoGamelle.cpp

${OBJECTDIR}/_ext/1617827895/AnimallToolQeoLogger.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/AnimallToolQeoLogger.o /home/zeus/NetBeansProjects/SenderAnimallCmd/AnimallToolQeoLogger.cpp

${OBJECTDIR}/_ext/1617827895/QeoAnimalEventMessage.o: /home/zeus/NetBeansProjects/SenderAnimallCmd/QeoAnimalEventMessage.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1617827895
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1617827895/QeoAnimalEventMessage.o /home/zeus/NetBeansProjects/SenderAnimallCmd/QeoAnimalEventMessage.c

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/senderanimallcmd

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
