TEMPLATE = subdirs
SUBDIRS += \
    src/BaseClass \
    src/ControlFactory\
    src/OneControlFactroy\
    src/MainWindow

include(SimulationTool.pri)

OTHER_FILES += \
    design/record
