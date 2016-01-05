TEMPLATE = subdirs
SUBDIRS += \
    src/MainWindow \
    src/BaseClass \
    src/ControlFactory


include(SimulationTool.pri)

OTHER_FILES += \
    design/record
