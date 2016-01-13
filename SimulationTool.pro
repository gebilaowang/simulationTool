TEMPLATE = subdirs
SUBDIRS += \
    src/Core\
    src/BaseClass \
    src/ControlFactory\
    src/OneControlFactroy\
    src/MainWindow


include(SimulationTool.pri)

OTHER_FILES += \
    design/record
