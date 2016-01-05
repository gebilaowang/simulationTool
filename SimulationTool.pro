TEMPLATE = subdirs
SUBDIRS += \
    src/MainWindow \
    src/BaseClass \
    src/ControlFactory\
    src/OneControlFactroy

include(SimulationTool.pri)

OTHER_FILES += \
    design/record
