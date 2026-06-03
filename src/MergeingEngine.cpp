#include <iostream>
#include <qpdf/QPDF.hh>
#include <qpdf/QPDFPageDocumentHelper.hh>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cerr << "During Compilation use this format -> " << "<File1.pdf> "
              << "<File2.pdf> "
              << "<output_file.pdf> \n"; // hardcoded use sys calls to create
                                         // non existing files and stuff
    return 1;
  }
  std::string f1 = argv[1];
  std::string f2 = argv[2];
  std::string out = argv[3];

  try {
    QPDF pdf1;
    pdf1.processFile(f1.c_str());

    QPDF pdf2;
    pdf2.processFile(f2.c_str());

    QPDFPageDocumentHelper dh1(pdf1);
    QPDFPageDocumentHelper dh2(pdf2);

    std::vector<QPDFPageObjectHelper> pages2 = dh2.getAllPages();

    for (auto &page : pages2) {
      dh1.addPage(page, false);
    }
    QPDFWriter writer(pdf1, out.c_str());
    writer.setStaticID(true);
    writer.write();

    std::cout << "Merged \n";

  } catch (std::exception e) {
    std::cerr << "Cooked\n";
    return 1;
  }
  return 0;
}
