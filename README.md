void generarReportePacientesPDF(const std::vector<Paciente>& pacientes) {
    // Crear un nuevo documento PDF
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Error al crear el PDF." << std::endl;
        return;
    }

    // Crear una nueva página
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    // Establecer la fuente y el tamaño
    HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize(page, font, 12);

    // Escribir el encabezado
    HPDF_Page_BeginText(page);
    HPDF_Page_MoveTextPos(page, 50, 750); // Posicionar el texto en la página
    HPDF_Page_ShowText(page, "Reporte de Pacientes Activos");
    HPDF_Page_MoveTextPos(page, 0, -30); // Mover la posición del texto hacia abajo

    bool hayPacientesActivos = false;

    // Iterar sobre los pacientes y agregar solo los activos
    for (const Paciente& paciente : pacientes) {
        if (paciente.activo) {
            hayPacientesActivos = true;
            std::string infoPaciente = "DPI: " + paciente.numeroIdentificacion + ", Nombre: " + paciente.nombreCompleto +
                                       ", Edad: " + std::to_string(paciente.edad) + ", Genero: " + paciente.genero +
                                       ", Direccion: " + paciente.direccion + ", Celular: " + std::to_string(paciente.numeroCelular) +
                                       ", Fecha Ingreso: " + paciente.fechaIngreso + ", Diagnostico: " + paciente.diagnostico;

            // Mostrar la información del paciente en el PDF
            HPDF_Page_ShowText(page, infoPaciente.c_str());
            HPDF_Page_MoveTextPos(page, 0, -20); // Mover el texto hacia abajo para el siguiente paciente
        }
    }

    if (!hayPacientesActivos) {
        HPDF_Page_ShowText(page, "No hay pacientes activos en este momento.");
    }

    HPDF_Page_EndText(page);

    // Guardar el archivo en disco
    HPDF_SaveToFile(pdf, "reporte_pacientes.pdf");

    // Limpiar memoria
    HPDF_Free(pdf);

    std::cout << "Reporte generado exitosamente: reporte_pacientes.pdf" << std::endl;
}
